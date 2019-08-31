//举例一个hash的模式
export class Base {

  constructor (router) {
    this.router = router
    this.current = {
      path: '/',
      query: {},
      params: {},
      name: '',
      fullPath: '/',
      route: {}
    }
  }


  /**
   * 路由转换
   * @param target 目标路径
   * @param cb 成功后的回调
   */
  transitionTo(target, cb) {
    // 通过对比传入的 routes 获取匹配到的 targetRoute 对象
    //注意，这里无需触发什么，只需要改变current的值，视图会更新的，如果是代码形式的
    //需要主动调用push方法或者replace方法....
    const targetRoute = match(target, this.router.routes)
    this.confirmTransition(targetRoute, () => {
      this.current.route = targetRoute
      this.current.name = targetRoute.name
      this.current.path = targetRoute.path
      this.current.query = targetRoute.query || getQuery()
      this.current.fullPath = getFullPath(this.current)
      cb && cb()
    })
  }

  /**
   * 确认跳转
   * @param route
   * @param cb
   */
  confirmTransition (route, cb) {
    // 钩子函数执行队列
    let queue = [].concat(
      this.router.beforeEach,
      this.current.route.beforeLeave,
      route.beforeEnter,
      route.afterEnter
    )

    // 通过 step 调度执行
    let i = -1
    const step = () => {
      i ++
      if (i > queue.length) {
        cb()
      } else if (queue[i]) {
        queue[i](step)
      } else {
        step()
      }

    }
    step(i)
  }
}

function getFullPath ({ path, query = {}, hash = '' }, _stringifyQuery){
  const stringify = _stringifyQuery || stringifyQuery
  return (path || '/') + stringify(query) + hash
}

export function match(path, routeMap) {
  let match = {}
  if (typeof path === 'string' || path.name === undefined) {
    for(let route of routeMap) {
      if (route.path === path || route.path === path.path) {
        match = route
        break;
      }
    }
  } else {
    for(let route of routeMap) {
      if (route.name === path.name) {
        match = route
        if (path.query) {
          match.query = path.query
        }
        break;
      }
    }
  }
  return match
}

//继承来的HashHistory对象
export class HashHistory extends Base {
  constructor (router) {
    super(router)
    this.ensureSlash()//主要是为了兼容历史记录，使用replaceState和pushState来记录历史
    //如果当hash的值发生变化的时候，改变了current的值
    window.addEventListener('hashchange', () => {
      this.transitionTo(this.getCurrentLocation())
    })
  }
}
//继承来的HTML5History对象
export class HTML5History extends Base {
  constructor (router) {
    super(router)
    //监听当前的历史节点页面加载的时候确实会触发popState事件
    window.addEventListener('popstate', () => {
      this.transitionTo(getLocation())
    })
  }
}


//router对象
class Router {
  constructor(options) {
    this.base = options.base
    this.routes = options.routes //路由信息
    this.container = options.id
    this.mode = options.mode || 'hash'
    this.fallback = this.mode === 'history' && !supportsPushState && options.fallback !== false
    if (this.fallback) {
      this.mode = 'hash'
    }

    this.history = this.mode === 'history' ? new HTML5History(this) : new HashHistory(this)

    Object.defineProperty(this, 'route', {
      get: () => {
        return this.history.current
      }
    })

    this.init()
  }

  push(location) {
    this.history.push(location)
  }

  replace(location) {
    this.history.replace(location)
  }

  go (n) {
    this.history.go(n)
  }

  render() {
    let i
    //这招神了....
    if ((i = this.history.current) && (i = i.route) && (i = i.component)) {
      document.getElementById(this.container).innerHTML = i
    }
  }

  init() {
    const history = this.history
    //监听this.history.current数据
    observer.call(this, this.history.current)
    //当this.history.current中的route发生变化的时候执行render函数
    new Watcher(this.history.current, 'route', this.render.bind(this))
    //跳转到当前所在的地址
    history.transitionTo(history.getCurrentLocation())
  }

}

window.Router = Router

//调用的时候的代码


var router = new Router({
  id: 'router-view',
  mode: 'hash',
  routes: [
    {
      path: '/',
      name: 'home',
      component: '<div>Home</div>',
      beforeEnter: (next) => {
        console.log('before enter home')
        next()
      },
      afterEnter: (next) => {
        console.log('enter home')
        next()
      },
      beforeLeave: (next) => {
        console.log('start leave home')
        next()
      }
    },
  ]
})
let Vue;
const _forEach = (obj,callback)=>{
    Object.keys(obj).forEach(key=>{
        callback(key,obj[key]);
    })
}
class ModuleConnection {
    constructor(options){
        this.register([],options);
    }
    register(path,rootModule){
        let newModule = {
            _raw:rootModule,
            _children:{},
            state:rootModule.state
        }
        if(path.length === 0){
            this.root = newModule; //注册根模块，一开始传进来的模块
        }else{
            path.slice(0,-1).reduce((root,current)=>{
                return this.root._children[current];
            },this.root);
            this.root._children[path[path.length-1]] = newModule;
        }
        //如果这个模块还有其他的子模块的话，递归注册模块
        if(rootModule.modules){
            _forEach(rootModule.modules,(moduleName,module)=>{
                this.register(path.concat(moduleName),module)
            })
        }
    }

}
const installModule = (store,state,path,rootModule)=>{
    if(path.length > 0) {
        let parent = path.slice(0, -1).reduce((state, current)=>{
            return state[current]
        }, state);
        Vue.set(parent, path[path.length - 1], rootModule.state);
    }


    let getters = rootModule._raw.getters
    if (getters) { // 
        _forEach(getters, (getterName, fn) => {
            Object.defineProperty(store.getters, getterName, {
                get: () => {
                    return fn(rootModule.state);
                }
            })
        })
    }

    let mutations = rootModule._raw.mutations;
    if(mutations) {
        _forEach(mutations, (mutationName, fn) => {
            let arr = store.mutations[mutationName] || (store.mutations[mutationName] = []);
            arr.push((payload) => {
                fn(rootModule.state, payload);
            });
        }) 
    }

    let actions = rootModule._raw.actions;
    if(actions) {
        _forEach(actions, (actionsName, fn) => {
            let arr = store.actions[actionsName] || (store.actions[actionsName]= []);
            arr.push((payload) => {
                fn(store, payload);
            });
        }) 
    }

    _forEach(rootModule._children, (moduleName, module) => {
        installModule(store, state, path.concat(moduleName), module);
    })
}
class Store {
    constructor(options){
        this._s = new Vue({
            data(){
                return {
                    state:options.state //把state变成可监控的对象
                }
            }
        });
    this.getters = {};
    this.mutation = {};
    this.actions = {};
    // 把getters属性定义到 this.getters中，并根据状态的变化，重新执行此函数
        // _forEach(getters, (getterName, value) => {
        //     Object.defineProperty(this.getters, getterName, {
        //         get: () => {
        //             return value(this.state)
        //         },
        //         enumerable: true 
        //     });
        // });

        // let mutations = options.mutations || {};
        // // this.mutations = {};
        // _forEach(mutations, (mutationName, value) => {
        //     // 先把用户传过来的mutation放到store上
        //     this.mutations[mutationName] = (payload) => {
        //         value.call(this, this.state, payload);
        //     }
        // })

        // let actions = options.actions || {};
        // // this.actions = {};
        // _forEach(actions, (actionName, value) => {
        //     this.actions[actionName] = (payload) => {
        //         value.call(this, this, payload);
        //     }
        // })
    //vuex模块化
    this.modules = new ModuleConnection(options);
    installModule(this,this.state,[],this.modules.root);   
    }
    commit = (type,payload)=>{
        this.mutation[type].forEach(fn=>fn(payload));
    }
    dispatch = (type,payload)=>{
        this.actions[type].forEach(fn=>fn(payload));
    }
    get state(){
        return this._s.state;
    }

}
const install = (_Vue)=>{
    Vue = _Vue;
    Vue.mixin({
        beforeCreate(){
            //需要给每个组件都注册一个this.$store的属性
            //需要判断是父组件还是子组件，如果是子组件，应该吧父组件的store增加给子组件
            if(this.$options && this.$options.store){
                this.$store = this.$options.store;
            }else{
                this.$store = this.$parent && this.$parent.$store;
            }
        }
    })
}
//使用的时候是这样的
// export default new Vuex.Store({
//     modules:{},
//     state:{},
//     actions:{},
//     getters:{},
//     mutations:{}
// })
// new Vue({
//     store
// })
export default {
    install,
    Store
}
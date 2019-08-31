//hash模式的跳转
window.addEventListener('hashchange', () => {
    this.transitionTo(this.getCurrentLocation())
})

function getCurrentLocation() {
    const href = window.location.href
    const index = href.indexOf('#')
    return index === -1 ? '' : href.slice(index + 1)
}
function changeUrl(path, replace) {
    const href = window.location.href
    const i = href.indexOf('#')
    const base = i >= 0 ? href.slice(0, i) : href
    if (replace) {
      window.history.replaceState({}, '', `${base}#/${path}`)
    } else {
      window.history.pushState({}, '', `${base}#/${path}`)
    }
}
//HTML5模式的跳转
window.addEventListener('popstate', () => {
    this.transitionTo(getLocation())
})

function getLocation (base = ''){
    let path = window.location.pathname
    if (base && path.indexOf(base) === 0) {
      path = path.slice(base.length)
    }
    return (path || '/') + window.location.search + window.location.hash
}
  
function changeUrl(base, path, replace) {
    if (replace) {
        window.history.replaceState({}, '', (base + path).replace(/\/\//g, '/'))
      } else {
        window.history.pushState({}, '', (base + path).replace(/\/\//g, '/'))
      }  
}

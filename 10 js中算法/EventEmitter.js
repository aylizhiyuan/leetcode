function EventEmitter (){
    this.events = {};
    this._maxListeners = 10;
}
//将事件挂在到events对象上来
EventEmitter.prototype.on = function(type,listener){
    if(this.events[type]){
        //是否已经存在了类似的事件了
        this.events[type].push(listener);
    }else{
        this.events[type] = [listener];
    }
}
//触发该类型的事件
EventEmitter.prototype.emit = function(type){
    this.events[type] && this.events[type].forEach(listener => {
        listener.apply(this);
    });
}
module.exports = EventEmitter
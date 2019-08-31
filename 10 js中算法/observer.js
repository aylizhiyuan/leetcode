class Watcher {
    constructor(vm,expr,cb){
        this.vm = vm;
        this.expr = expr;
        this.cb = cb;
        this.value = this.get();
    }
    getVal(vm,expr){
        expr = expr.split('.');
        return expr.reduce((prev,next)=>{
            return prev[next];
        },vm);
    }
    get(){
        Dep.target = this;
        let value = this.getVal(this.vm,this.expr);
        Dep.target = null;
        return value;
    }
    update(){
        let newValue = this.getVal(this.vm,this.expr);
        let oldValue = this.value;
        if(newValue != oldValue){
            this.cb(newValue);
        }
    }
}
class Observer {
    constructor(data){
        this.observer(data);
    }
    observer(data){
        if(!data || typeof data != 'object'){
            return;
        }
        //要将数据进行劫持
        Object.keys(data).forEach(key=>{
            this.defineReactive(data,key,data[key]);
            this.observer(data[key]);
        })
    }
    defineReactive(obj,key,value){
        let that = this;
        let dep = new Dep();
        Object.defineProperty(obj,key,{
            enumerable:true,
            configurable:true,
            get(){
                Dep.target && dep.addSub(Dep.target);
                return value;
            },
            set(newValue){
                if(newValue != value){
                    that.observer(newValue);
                    value = newValue;
                    dep.notify();
                }
            }
        })
    }
}
class Dep {
    constructor (){
        this.subs = [];
    }
    addSub(watcher){
        this.subs.push(watcher);
    }
    notify(){
        this.subs.forEach(watcher=>watcher.update());
    }
}

//使用的时候
var data = {
    name:'lzy'
}
var dosometing = function(){
    console.log(1);
}
new Observer(data);
new Watcher(data,'name',dosometing);
var res = data.name;
console.log(res);
//data.name = 'asdfadsfasdfasdf';
//输出this.$data.name 的值
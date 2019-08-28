function New(func){
    var res = {};
    //func是一个带有this的构造函数
    //将原型链中的方法赋值给res
    if(func.prototype !== null){
        res.__proto__ = func.prototype;
    }
    //这里只是简单的改变了一下func中this的指向而已
    //函数中的this指向了A
    var ret = func.apply(res,Array.prototype.slice.call(arguments,1));
    if((typeof ret == 'object') || typeof ret === "function" && ret != null){
        return ret;
    }
    return res;
    // {value:'lzy',run:function(){console.log("run")}};
}
var A = function(){
    this.value = 'lzy';
}
A.prototype.run = function(){
    console.log("run");
}
var obj = New(A,1,2);
Function.prototype.bind2 = function(content){
  if(typeof this != "function"){
    throw Error("not a function");
  }
  let fn = this;
  let args = [...arguments].slice(1);
  let resFn = function(){
    return fn.apply(this instanceof resFn ? this : content,args.concat(...arguments) );
  }
  function tmp(){}
  tmp.prototype = this.prototype;
  resFn.prototype = new tmp();
  return resFn;
}
//bind创建一个新的函数，新函数中的this指向他的第一个参数
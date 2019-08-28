function animal(){
    this.species = '动物';
}
animal.prototype.run = function(){
    alert('所有的动物都会跑');
}
animal.prototype.cc = 'ha';
function cat(name,color){
    //通过call改变了animal中的this指向，变成了cat
    animal.call(this);
    this.name = name;
    this.color = color;

}
//创建一个空的构造函数
//先从cat1自身开始找，找不到的话到cat1原型链中找(F对象,这个F对象只有原型链属性,而恰恰这个原型链里面的属性跟基类的是一样的)
//最终找到object对象完毕
var f = function(){};
f.prototype = animal.prototype;
cat.prototype = new f();
cat.prototype.constructor = cat;
var cat1 = new cat('大毛','黄色');
console.log(cat1);
//alert(animal.prototype.constructor);
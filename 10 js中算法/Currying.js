function curry(fn, args) {
    //函数参数的长度
    var length = fn.length;
    var args = args || [];
    return function(){
        //每次函数传递来的参数汇总
        newArgs = args.concat(Array.prototype.slice.call(arguments));
        //不满足参数长度的情况下，继续的合并参数
        //一旦合并参数够了以后，调用fn执行
        if (newArgs.length < length) {
            return curry.call(this,fn,newArgs);
        }else{
            return fn.apply(this,newArgs);
        }
    }
}

function multiFn(a, b, c) {
    return a * b * c;
}

var multi = curry(multiFn);

multi(2)(3)(4);
multi(2,3,4);
multi(2)(3,4);
multi(2,3)(4);
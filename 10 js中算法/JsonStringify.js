function josnstringify(obj){
    let type = typeof obj;
    if(type !== 'object'){
        if(/string|undefined|function/.test(type)){
            obj = '"' + obj + '"';
        }
        return String(obj);
    }else{
        //真正的转化
        let json = [];
        let arr = Array.isArray(obj);
        for(let k in obj){
            let v = obj[k];//值
            let type = typeof v;//值类型
            if(/string|undefined|function/.test(type)){
                v = '"' + v + '"';
            }else if(type === 'object'){
                v = josnstringify(v);
            }
            json.push(arr ? "" : '"' + k + '":' + String(v));
        }
        return (arr ? "[" : "{") + String(json) + (arr ? "]" : "}") 
    }
}
jsonStringify({x : 5}) // "{"x":5}"
jsonStringify([1, "false", false]) // "[1,"false",false]"
jsonStringify({b: undefined}) // "{"b":"undefined"}"
var china = {
    nation:'中国',
    birthPlaces : ['北京','上海','广州']
}
var doctor = {
    career:'医生'
}
function deepCopy(p,c){
    var c = c || {};
    for(var i in p){
        if(typeof p[i] === 'object'){
            c[i] = (p[i].constructor === Array) ? [] : {};
            deepCopy(p[i],c[i]);
        }else{
            c[i] = p[i];
        }
    }
    return c;
}
var result = deepCopy(china);
console.log(result);
china.birthPlaces = ['厦门'];
alert(china.birthPlaces);
alert(result.birthPlaces);
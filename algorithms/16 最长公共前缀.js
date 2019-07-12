/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length == 0){
        return "";
    }
    var curr = strs[0];
    var newStr = '';
    for(var i=1;i<strs.length;i++){
        for(var j=0;j<curr.length;j++){
            if(curr[j] != strs[i][j]){
                break;
            }
        }
        curr = curr.substr(0,j);
    }
    return curr;
};
console.log(longestCommonPrefix(['flower','flow','flight']));
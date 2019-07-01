/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    //列出所有的子串
    var all = [];
    for(var i=0;i<s.length;i++){
        //第一个字符和相邻的字符组成子串
        for(j=i+1;j<=s.length;j++){
            //这个就是所有的子串集合
            //如果返回true,说明是不重复的，否则就是重复的，我们就不放在数组里面了
            if(isUnion((s.slice(i,j)))){
                all.push(s.slice(i,j));
            };
        }
    }
    function isUnion(s){
        
    }
    
};
lengthOfLongestSubstring('pwwkew');
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    var max = '';
    var len = s.length;
    if(len < 2) return s;
    for(var i=0;i<=len;i++){
        for(var j=0;j<=len;j++){
            var child = s.slice(i,j);
            var child_len = child.length;
            var max_len = max.length;
            var arr = child.split('');
            var str1 = arr.join();
            var str2 = arr.reverse().join();
            if(str1 === str2 && max_len < child_len) max = child;
            child = chil_len = max_len = arr = str1 = str2 = null;
        }
    }
    return max;
};
longestPalindrome('pwwkew');
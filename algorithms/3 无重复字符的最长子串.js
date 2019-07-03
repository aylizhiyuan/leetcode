/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let num=0,j=0,t=0
    for(let i=0;i<s.length;i++){
        //获取你截取的新的字符串在原始字符串中的下标
        t = s.slice(j,i).indexOf(s[i]);
        //如果这个下标为-1,则意味着不包含这个字符
        if(t == -1){
            num=Math.max(num,i-j+1)
        }else{
            //意味着包含这个字符
            j=j+t+1
        }
    }
    return num
};
lengthOfLongestSubstring('pwwkew');
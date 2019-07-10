/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    var str = x.toString();
    var newStr = str.split('').reverse().join('');
    return str === newStr
};
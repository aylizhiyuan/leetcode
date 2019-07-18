/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    let len = str.length - 1, i = -1, sign, result = 0;
    while(i++ < len) {
        let c = str.charCodeAt(i);
        if (48 <= c && c <= 57) {
            sign = sign || 1;
            result = result * 10 + c - 48;
        } else if (sign) {
            break;
        } else if (c === 43) {
            sign = 1
        } else if (c === 45) {
            sign = -1;
        } else if (c !== 10 && c !== 13 && c !== 32) {
            return 0;
        }
    }
    result *= (sign || 1);
    return result < -2147483648 ? -2147483648 : (result > 2147483647 ? 2147483647: result);
};
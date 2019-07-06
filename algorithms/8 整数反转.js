/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
	x = x.toString();
	let ans = '', isNegative = false;
	for (let i = x.length - 1; i >= 0; i--) {
		if (x[i] === '-') {
			isNegative = true;
		} else {
			ans += x[i];
		}
	}
	ans = isNegative ? -Number(ans) : Number(ans);
	return ans <= 2147483647 && ans >= -2147483648 ? ans : 0;
};
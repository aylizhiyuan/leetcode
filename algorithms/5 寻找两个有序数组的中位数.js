/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    const tmp = arr1.concat(arr2).sort((a, b) => a - b);
    const tmp2 = tmp.slice(Math.ceil(tmp.length/ 2) - 1 , Math.floor(tmp.length /2 ) + 1);  // 切出来的长度为1或者2
    let num= 0;
    tmp2.map(item => num += item);
    return (num / tmp2.length);
};
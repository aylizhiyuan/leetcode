/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for(var i=0;i<nums.length;i++){
        var a = nums.indexOf((target-nums[i]),i+1);
        if(a !=-1){
            return [i,a];
        }
    }
};
//解决的思路其实应该是找到那个target-数组元素每个值看是否在数组中存在
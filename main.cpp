#include <stdio.h>
#include <vector>
int searchInsert(std::vector<int> &nums,int target){
    //二分查找的思想
    int index = -1;
    int begin = 0;
    int end = nums.size() - 1;
    while(index == -1){
        int mid = (begin + end) / 2;
        if(target == nums[mid]){
            index = mid;
        }else if(target < nums[mid]){
            end = mid - 1;
        }else if(target > nums[mid]){
            begin = mid + 1;
        }
    }
    return index;
}
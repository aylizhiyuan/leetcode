#include <stdio.h>

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int index = -1;
		int begin = 0;
		int end = nums.size() - 1;
		while (index == -1){
			int mid = (begin + end) / 2;
			if (target == nums[mid]){
				index = mid;
			}
			else if (target < nums[mid]){
				if (mid == 0 || target > nums[mid - 1]){
					index = mid;
				}
				end = mid - 1;
			}
			else if (target > nums[mid]){
				if (mid == nums.size() - 1 || target < nums[mid + 1]){
					index = mid + 1;
				}
				begin = mid + 1;
			}
		}
		return index;
    }
};

int main(){
	int test[] = {1, 3, 5, 6};
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 4; i++){
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 8; i++){
		printf("i = %d index = %d\n", i, solve.searchInsert(nums, i));
	}
	return 0;
}

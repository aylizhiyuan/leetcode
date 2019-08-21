#include <stdio.h>

#include <vector>

int binary_search(std::vector<int> nums, int target){
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

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
    	if (nums.size() == 0){
	    	return 0;
	    }
	    std::vector<int> stack;
	    stack.push_back(nums[0]);
	    for (int i = 1; i < nums.size(); i++){
	    	if (nums[i] > stack.back()){
	    		stack.push_back(nums[i]);
	    	}
	    	else{
	    		int pos = binary_search(stack, nums[i]);
	    		stack[pos] = nums[i];
	    	}
    	}
        return stack.size();
    }
};

int main(){
	int test[] = {1, 3, 2, 3, 1, 4};
	std::vector<int> nums;
	for (int i = 0; i < 6; i++){
		nums.push_back(test[i]);
	}
	Solution solve;
	printf("%d\n", solve.lengthOfLIS(nums));
	return 0;
}

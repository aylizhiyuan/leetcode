#include <stdio.h>

#include <vector>
class Solution {
public:
    int jump(std::vector<int>& nums) {
    	if (nums.size() < 2){
	    	return 0;
	    }
        int current_max_index = nums[0];
        int pre_max_max_index = nums[0];
        int jump_min = 1;
        for (int i = 1; i < nums.size(); i++){
        	if (i > current_max_index){
        		jump_min++;
	        	current_max_index = pre_max_max_index;
	        }
        	if (pre_max_max_index < nums[i] + i){
       			pre_max_max_index = nums[i] + i;
        	}
        }
        return jump_min;
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	Solution solve;
	printf("%d\n", solve.jump(nums));
	return 0;
}

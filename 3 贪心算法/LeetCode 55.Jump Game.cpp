#include <stdio.h>

#include <vector>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        std::vector<int> index;
        for (int i = 0; i < nums.size(); i++){
        	index.push_back(i + nums[i]);
        }
        int jump = 0;
        int max_index = index[0];
        while(jump < index.size() && jump <= max_index){
        	if (max_index < index[jump]){
	        	max_index = index[jump];
	        }
        	jump++;
        }
        if (jump == index.size()){
        	return true;
        }
        return false;
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
	printf("%d\n", solve.canJump(nums));
	return 0;
}

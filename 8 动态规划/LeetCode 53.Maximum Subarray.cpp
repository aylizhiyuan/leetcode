#include <stdio.h>

#include <vector>
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
    	std::vector<int> dp(nums.size(), 0);
    	dp[0] = nums[0];
    	int max_res = dp[0];
    	for (int i = 1; i < nums.size(); i++){
	    	dp[i] = std::max(dp[i-1] + nums[i], nums[i]);
	    	if (max_res < dp[i]){
	    		max_res = dp[i];
	    	}
	    }
        return max_res;
    }
};

int main(){
	Solution solve;
	std::vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	printf("%d\n", solve.maxSubArray(nums));
	return 0;
}

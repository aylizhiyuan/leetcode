#include <stdio.h>
#include <iostream>
#include <vector>
void print( std::vector<int> vector1){
    for(int i=0 ;i<vector1.size();i++)
        std::cout<<vector1[i]<<" ";
 
    std::cout<<std::endl;
}
class Solution {
    public: 
    bool canJump(std::vector<int>& nums){
        std::vector<int> index;
        //上述记录最远可跳跃的数组下标
        int jump = 0;
        int max_index = index[0];
        //jump一直往前跳即可,如果它超过了当前记录的最大的下标值那说明我们无法达到
        //如果在不超越我们最大的跳跃范围内，找到了更大的值我们就更新当前记录的最大下标值继续跳跃
        while(jump < index.size() && jump <= max_index){
            if(max_index < index[jump]){
                max_index = index[jump];
            }
            jump++;
        }
        if(jump == index.size()){
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
    printf("%d\n",solve.canJump(nums));
    return 0;
}
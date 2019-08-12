#include <vector>
#include <stdio.h>
class Solution {
    public: 
        int wiggleMaxLength(std::vector<int>& nums){
            if(nums.size() < 2){
                return nums.size();
            }
            static const int BEGIN = 0;
            static const int UP = 1;
            static const int DOWN = 2;
            int STATE = BEGIN;
            int max_length = 1;
            for(int i=1;i<nums.size();i++){
                //从第二个元素开始扫描
                switch(STATE){
                    case BEGIN: 
                        if(nums[i-1] < nums[i]){
                            //第二个数比第一个数大
                            STATE = UP;
                            max_length++;
                        }else if(nums[i-1] > nums[i]){
                            //第二个数比第一个数小
                            STATE = DOWN;
                            max_length++;
                        }
                        break;
                    case UP:
                        //在已知上一个状态上升的情况下
                        //在下一个状态是下降的时候再加
                        if(nums[i-1] > nums[i]){
                            STATE = DOWN;
                            max_length++;
                        }
                        break;
                    case DOWN:
                        if(nums[i-1] < nums[i]){
                            STATE = UP;
                            max_length++;
                        }   
                        break;     
                }
            }
            return max_length;
        }
};
int main(){
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(17);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(13);
    nums.push_back(15);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(16);
    nums.push_back(8);
    Solution solve;
    printf("%d\n",solve.wiggleMaxLength(nums));
    return 0;
}
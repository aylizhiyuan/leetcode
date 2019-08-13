#include <vector>
class Solution {
    public: 
        std::vector<std::vector<int> > subsets(std::vector<int>& nums){
            std::vector<std::vector<int> > result; //存放最终结果的数组
            std::vector<int> item; //回溯的时候产生各个子集的数组
            result.push_back(item);
            generate(0,nums,item,result);
            return result;
        }
    private: 
        void generate(int i,std::vector<int>& nums,
        std::vector<int>& item,std::vector<std::vector<int> >& result
        ){
            if(i >= nums.size()){
                return;
            }
            item.push_back(nums[i]);
            result.push_back(item);
            generate(i+1,nums,item,result);
            item.pop_back();
            generate(i+1,nums,item,result);
        }
};
int main(){
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    std::vector<std::vector<int> > result;
    Solution solve;
    result = solve.subsets(nums);
    for(int i=0;i<result.size();i++){
        if(result[i].size() == 0){
            printf("[]");
        }
        for(int j=0;j<result[i].size();j++){
            printf("[%d]",result[i][j]);
        }
        printf("\n");
    }
}
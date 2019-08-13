#include <vector>
#include <set>
#include <algorithm>
class Solution {
    public: 
        std::vector<std::vector<int> > combinationSum2(std::vector<int>& candidates,int target) {
            std::vector<std::vector<int> > result;
            std::vector<int> item;
            std::set<std::vector<int> > res_set;
            std::sort(candidates.begin(),candidates.end());
            generate(0,candidates,result,item,res_set,0,target);
            return result;
        }
    private:
        void generate(int i,std::vector<int>& nums,std::vector<std::vector<int> > &result,
        std::vector<int> &item,
        std::set<std::vector<int> > &res_set,
        int sum,int target){
            if(i >= nums.size() || sum > target){
                return; //当元素已选择的元素之和超过target之后就无须继续了
            }
            //sum来计算元素之和
            sum += nums[i];
            //item依然用来保存数组中的每一个元素
            item.push_back(nums[i]);
            if(target == sum && res_set.find(item) == res_set.end()){
                result.push_back(item);
                res_set.insert(item);
            }
            generate(i+1,nums,result,item,res_set,sum,target);
            sum -= nums[i];
            item.pop_back();
            generate(i+1,nums,result,item,res_set,sum,target);
        }    
};
int main(){
    std::vector<int> nums;
    nums.push_back(10);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(5);
    std::vector<std::vector<int> > result;
    Solution solve;
    result = solve.combinationSum2(nums,8);
    for(int i=0;i<result.size();i++){
        if(result[i].size() == 0){
            printf("[]");
        }
        for(int j=0;j<result[i].size();j++){
            printf("[%d]",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

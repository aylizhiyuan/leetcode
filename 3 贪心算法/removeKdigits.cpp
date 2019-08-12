//移除k个数字
#include <stdio.h>
#include <string>
#include <vector>
class Solution {
    public: 
        std::string removeKdigits(std::string num,int k){
            std::vector<int> S; //使用容器当做栈
            std::string result = ""; //存储最终的结果
            for(int i=0;i<num.length();i++){
                int number = num[i] - '0';//转整数
                //1. 当栈不为空
                //2. k不为零
                //3. 栈顶元素大于数字num[i]
                while(S.size() != 0 && S[S.size()-1] > number && k > 0){
                    S.pop_back();
                    k--;
                }
                //将更小的数字压入栈，将大得数字出站
                //处理number如果是0的话，将
                if(number != 0 || S.size() != 0){
                    S.push_back(number);
                }
            }
            //这里考虑的是所有的数字都是递增的情况，那么他们就会全部放在栈中
            //这时候删除谁呢？把最后面的删除掉即可
            while(S.size() != 0 && k > 0){
                S.pop_back();
                k--;
            }
            for(int i=0;i<S.size();i++){
                result.append(1,'0'+S[i]);
            }
            if(result == ""){
                result = "0";
            }
            return result;
        }        
};
int main(){
    Solution solve;
    std::string result = solve.removeKdigits("1432219",3);
    printf("%s\n",result.c_str());
    std::string result2 = solve.removeKdigits("100200",1);
    printf("%s\n",result2.c_str());
    return 0;
}
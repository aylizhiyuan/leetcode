#include <vector>
#include <stdio.h>
#include <string>
class Solution {
    public: 
        std::vector<std::string> generateParenthesis(int n){
            std::vector<std::string> result;
            generate("",n,n,result);
            return result;
        }
    private: 
        void generate(std::string item,int left,int right,std::vector<std::string> &result){
            if(left == 0 && right == 0){
                result.push_back(item);
                return;
            }
            if(left > 0){
                generate(item+'(',left-1,right,result);
            }
            if(left < right){
                generate(item+')',left,right-1,result);
            }
        }    
};
int main(){
    Solution solve;
    std::vector<std::string> result = solve.generateParenthesis(3);
    for(int i=0;i<result.size();i++){
        printf("%s\n",result[i].c_str());
    }
    return 0;
}

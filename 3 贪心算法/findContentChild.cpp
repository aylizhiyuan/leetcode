//糖果满足孩子的问题
#include <stdio.h>
#include <vector>
#include <algorithm>
class Solution {
    public: 
        int findContentChildren(std::vector<int>& g,std::vector<int> &s){
            std::sort(g.begin(),g.end());
            std::sort(s.begin(),s.end());
            int child = 0;
            int cookie = 0;
            while(child < g.size() && cookie < s.size()){
                if(g[child] <= s[cookie]){
                    child++;//该糖果满足了孩子，孩子指针child向后移动
                }
                cookie++;//每次糖果只尝试一次，cookie向后移动
            }
            return child;
        };
};
int main(){
    Solution solve;
    std::vector<int> g;
    std::vector<int> s;
    g.push_back(5);
    g.push_back(10);
    g.push_back(2);
    g.push_back(9);
    g.push_back(15);
    g.push_back(9);
    s.push_back(6);
    s.push_back(1);
    s.push_back(20);
    s.push_back(3);
    s.push_back(8);
    printf("%d\n",solve.findContentChildren(g,s));
    return 0;
}
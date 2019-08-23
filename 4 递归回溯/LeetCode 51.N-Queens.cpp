#include <vector>
#include <string>
#include <stdio.h>
class Solution {
    public: 
        std::vector<std::vector<std::string> > solveNQueens(int n){
            std::vector<std::vector<std::string> > result; //存放最终结果的数组
            std::vector<std::vector<int> > mark; //标记棋盘是否可以放置皇后的二维数组
            std::vector<std::string> location;//存储某个摆放结果，当完成一次递归找到结果后，将location push到result
            for(int i=0;i<n;i++){
                mark.push_back((std::vector<int>()));
                for(int j=0;j<n;j++){
                    mark[i].push_back(0);
                }
                location.push_back("");
                location[i].append(n,'.');
            }
            generate(0,n,location,result,mark);
            return result;
        }
    private: 
        void put_down_the_queen(int x,int y,std::vector<std::vector<int> > &mark){
            static const int dx[] = {-1,1,0,0,-1,-1,1,1};
            static const int dy[] = {0,0,-1,1,-1,1,-1,1}; //方向数组
            mark[x][y] = 1;
            for(int i=1;i<mark.size();i++){
                for(int j=0;j<8;j++){
                    int new_x = x + i * dx[j];
                    int new_y = y + i * dy[j];
                    if(new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()){
                        mark[new_x][new_y] = 1;
                    }
                }
            }
        }
        void generate(int k,int n,
        std::vector<std::string>& location,
        std::vector<std::vector<std::string> > result,
        std::vector<std::vector<int> > mark){
            if(k == n){
                result.push_back(location);
                return;
            }
            for(int i=0;i<n;i++){
                if(mark[k][i] == 0){
                    std::vector<std::vector<int> > tmp_mark = mark;
                    location[k][i] = 'Q';
                    put_down_the_queen(k,i,mark);
                    generate(k+1,n,location,result,mark);
                    mark = tmp_mark;
                    location[k][i] = '.';
                }
            }
        }    
};
int main(){
    std::vector<std::vector<std::string> > result;
    Solution solve;
    result = solve.solveNQueens(4);
    for(int i=0;i<result.size();i++){
        printf("i=%d\n",i);
        for(int j=0;j<result[i].size();j++){
            printf("%s\n",result[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}
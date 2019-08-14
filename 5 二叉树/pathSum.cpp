#include <stdio.h>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};
class Solution {
    public: 
        std::vector<std::vector<int> > pathSum(TreeNode* root,int sum){
            //存放结果的数组
            std::vector<std::vector<int> > result; 
            std::vector<int> path; //路径栈与路径值
            int path_value = 0;
            preorder(root,path_value,sum,path,result);
            return result;
        }
    private: 
        void preorder(TreeNode* node,int &path_value,int sum,std::vector<int>& path,std::vector<std::vector<int> > &result){
            if(!node){
                return;
            }
            //在刚一开始访问这个节点的时候就讲该节点的值累加
            //累加的时候将值入栈,看一下这时候path_value的值是否满足了条件了
            //否则就继续遍历左子树和右子树,遍历完成后,回到该节点的时候还未发现满足条件，则将
            //当前的节点的数值不做累加
            path_value += node->val; //遍历一个节点就累加一下值
            path.push_back(node->val);//将累加的所有节点入栈
            if(!node->left && !node->right && path_value == sum){
                result.push_back(path);
            }
            preorder(node->left,path_value,sum,path,result);
            preorder(node->right,path_value,sum,path,result);
            //在后续遍历到最终的叶子节点的时候
            //每离开一个节点就将值不做累加
            path_value -= node->val;
            path.pop_back();
        }    
};
int main(){
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &x;
    f.right = &y;
    Solution solve;
    std::vector<std::vector<int> > result = solve.pathSum(&a,22);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            printf("[%d]",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//二叉树转链表
#include <stdio.h>
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
class Solution {
    public: 
        void flatten(TreeNode* root){
            TreeNode *last = NULL;
            preorder(root,last);
        }
    private: 
        void preorder(TreeNode* node,TreeNode *&last){
            if(!node){
                return;
            }
            if(!node->left && !node->right){
                last = node;
                return;
            }
            TreeNode *left = node->left;
            TreeNode *right = node->right;
            TreeNode *left_last = NULL;
            TreeNode *right_last = NULL;
            //这个是先递归把二叉树的左子树练成一个链表
            //
            if(left){
                preorder(left,left_last);
                node->left = NULL;
                node->right = left;
                //都是指针，赋值相当于将left_last的指针赋值给last，那么当last值发生变化的时候
                //left_last也会发生变化，目的是为了指向左子树最后一个元素
                last = left_last;
            }
            if(right){
                preorder(right,right_last);
                if(left_last){
                    left_last->right = right;
                }
                last = right_last;
            }
        }    
};
int main(){
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    Solution solve;
    solve.flatten(&a);
    TreeNode *head = &a;
    while(head){
        if(head->left){
            printf("ERROR\n");
        }
        printf("[%d]",head->val);
        head = head->right;
    }
    printf("\n");
    return 0;
}


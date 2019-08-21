#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>
class Solution {
public:
    void flatten(TreeNode *root) {
    	std::vector<TreeNode *> node_vec;
    	preorder(root, node_vec);
    	for (int i = 1; i < node_vec.size(); i++){
	    	node_vec[i-1]->left = NULL;
	    	node_vec[i-1]->right = node_vec[i];
	    }
    }
private:
	void preorder(TreeNode *node, std::vector<TreeNode *> &node_vec){
		if (!node){
			return;
		}
		node_vec.push_back(node);
		preorder(node->left, node_vec);
		preorder(node->right, node_vec);
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
		if (head->left){
			printf("ERROR\n");
		}
		printf("[%d]", head->val);
		head = head->right;
	}
	printf("\n");
	return 0;
}

#include <stdio.h>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void BST_insert(TreeNode *node, TreeNode *insert_node){
	if (insert_node->val < node->val){
		if (node->left){
			BST_insert(node->left, insert_node);
		}
		else{
			node->left = insert_node;
		}
	}
	else{
		if (node->right){
			BST_insert(node->right, insert_node);
		}
		else{
			node->right = insert_node;
		}
	}
}

void preorder_print(TreeNode *node,int layer){
	if (!node){
		return;
	}
	for (int i = 0; i < layer; i++){
		printf("-----");
	}
	printf("[%d]\n", node->val);
	preorder_print(node->left, layer + 1);
	preorder_print(node->right, layer + 1);
}

int main(){
	TreeNode root(8);
	std::vector<TreeNode *> node_vec;
	int test[] = {3, 10, 1, 6, 15};
	for (int i = 0; i < 5; i++){
		node_vec.push_back(new TreeNode(test[i]));
	}
	for (int i = 0; i < node_vec.size(); i++){
		BST_insert(&root, node_vec[i]);
	}
	preorder_print(&root, 0);
	return 0;
}

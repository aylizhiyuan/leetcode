#include "AVL.h"
#include <iostream>
AVL* New_Node(KEY_TYPE key, AVL* lchild, AVL* rchild, int height)
{
	AVL* p_avl = new AVL;
	p_avl->key = key;
	p_avl->lchild = lchild;
	p_avl->rchild = rchild;
	p_avl->height = height;
	return p_avl;
}

inline int getHeight(AVL* node)
{
	return (node==NULL)? -1:node->height;
}

inline int max(int a, int b)
{
	return a>b?a:b;
}

/* RR(Y rotates to the right):
        k2                   k1
       /  \                 /  \
      k1   Z     ==>       X   k2
     / \                      /  \
    X   Y                    Y    Z
*/
/*
 Return which the root pointer(at a higher level) should point to
 */
//右旋的操作，原因是左左造成了失衡
AVL* RR_Rotate(AVL* k2)
{
	AVL* k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;
	k2->height = max(getHeight(k2->lchild), getHeight(k2->rchild)) + 1;
	k1->height = max(getHeight(k1->lchild), k2->height) + 1;
	return k1;
}

/* LL(Y rotates to the left):
        k2                       k1
       /  \                     /  \
      X    k1         ==>      k2   Z
          /  \                /  \
         Y    Z              X    Y
 */
//左旋的操作，原因是右右造成了失衡
AVL* LL_Rotate(AVL* k2)
{
	AVL* k1 = k2->rchild;
	k2->rchild = k1->lchild;
	k1->lchild = k2;
	k2->height = max(getHeight(k2->lchild), getHeight(k2->rchild)) + 1;
	k1->height = max(getHeight(k1->rchild), k2->height) + 1;
	return k1;
}



/* LR(B rotates to the left, then C rotates to the right):
      k3                         k3                       k2
     /  \                       /  \                     /  \
    k1   D                     k2   D                   k1   k3
   /  \         ==>           /  \        ==>          / \   / \
  A    k2                    k1   C                   A  B  C   D
      /  \                  /  \
     B    C                A    B
*/
/*
 Return which the root pointer should point to
 */
//先左旋后右旋，原因是左右造成了失衡
AVL* LR_Rotate(AVL* k3)
{
	k3->lchild = LL_Rotate(k3->lchild);
	return RR_Rotate(k3);
}


/* RL(D rotates to the right, then C rotates to the left):
       k3                         k3                          k2
      /  \                       /  \                        /  \
     A    k1                    A    k2                     k3   k1 
         /  \       ==>             /  \         ==>       /  \  / \
        k2   B                     C    k1                A   C D   B
       /  \                            /  \
      C    D                          D    B 
 */
//先右后左，原因是右左造成了失衡
AVL* RL_Rotate(AVL* k3)
{
	k3->rchild = RR_Rotate(k3->rchild);
	return LL_Rotate(k3);
}

//插入操作，传入的参数是根节点和待插入的数据
//1. 首先我们要创建一个待插入的节点
//2. 然后我们要找到
AVL* Insert(AVL* root, KEY_TYPE key)
{
	//第一次插入的时候，初始化根节点
	if(root == NULL)
		return (root = New_Node(key, NULL, NULL));
	else if(key < root->key)
		//根节点的值与插入的值进行比较
		//如果根节点的值大，那么插入到根节点的左子树中，root变为根节点的左子树
		root->lchild = Insert(root->lchild, key);
	else //key >= root->key
		//如果插入的值大，那么久插入到根节点的右子树中,root变为根节点的右子树
		root->rchild = Insert(root->rchild, key);
	
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
	//左子树深度较深
	if(getHeight(root->lchild) - getHeight(root->rchild) == 2)
	{
		if(key < root->lchild->key)
			//失去平衡的情况是左左
			root = RR_Rotate(root);
		else
			//失去平衡的情况是左右
			root = LR_Rotate(root);
	}
	//右子树的深度较深
	else if(getHeight(root->rchild) - getHeight(root->lchild) == 2)
	{
		//失去平衡的情况是右左
		if(key < root->rchild->key)
			root = RL_Rotate(root);
		else
			//失去平衡的情况是右右
			root = LL_Rotate(root);
	}
	return root;
}


/* return which the root pointer(at an outer/higher level) should pointer to,
   cause the root_node of AVL tree may change frequently during delete/insert,
   so the Root pointer should point to the REAL root node.
 */
AVL* Delete(AVL* root, KEY_TYPE key)
{
	if(!root)
		return NULL;
	if(key == root->key)
	{
		if(root->rchild == NULL)
		{
			AVL* temp = root;
			root = root->lchild;
			delete(temp);
			return root;
		}
		else
		{
			AVL* temp = root->rchild;
			while(temp->lchild)
				temp = temp->lchild;
			/* replace the value */
			root->key = temp->key;
			/* Delete the node (successor node) that should be really deleted */
			root->rchild = Delete(root->rchild, temp->key);
		}
	}
	else if(key < root->key)
		root->lchild = Delete(root->lchild, key);
	else
		root->rchild = Delete(root->rchild, key);
	
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
	if(getHeight(root->rchild) - getHeight(root->lchild) == 2)
	{
		if(getHeight(root->rchild->rchild) >= getHeight(root->rchild->lchild))
			root = LL_Rotate(root);
		else
			root = RL_Rotate(root);
	}
	else if(getHeight(root->lchild) - getHeight(root->rchild) == 2)
	{
		if(getHeight(root->lchild->lchild) >= getHeight(root->lchild->rchild))
			root = RR_Rotate(root);
		else
			root = LR_Rotate(root);
	}
	return root;
}

void InOrder(AVL* root)
{
	if(root)
	{
		InOrder(root->lchild);
		printf("key: %d height: %d ", root->key, root->height);
		if(root->lchild)
			printf("left child: %d ", root->lchild->key);
		if(root->rchild)
			printf("right child: %d ", root->rchild->key);
		printf("\n");
		InOrder(root->rchild);
	}
}
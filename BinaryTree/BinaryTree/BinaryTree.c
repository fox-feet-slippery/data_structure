#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
#include"Queue.h"

// 创建新节点
BTNode* CreateBinaryTreeNode(BTDataType val)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("Memory allocation failed!");
		exit(1);
	}
	newnode->_left = newnode->_right = NULL;
	newnode->_val = val;
	return newnode;
}

// 插入节点
//对于二叉搜索树来说，左子树的节点值小于根节点值，右子树的节点值大于等于根节点值
void InsertBinaryTreeNode(BTNode** root, BTDataType val)
{
	if (*root == NULL)
	{
		*root = CreateBinaryTreeNode(val);
		return;
	}
	if (val < (*root)->_val) {
		InsertBinaryTreeNode(&((*root)->_left), val);
	}
	else {
		InsertBinaryTreeNode(&((*root)->_right), val);
	}
}

// 前序遍历---根左右
void PreorderTraversal(BTNode* root)
{

	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	printf("%d->", root->_val);
	PreorderTraversal(root->_left);
	PreorderTraversal(root->_right);
}

// 中序遍历---左根右
void InorderTraversal(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	InorderTraversal(root->_left);
	printf("%d ", root->_val);
	InorderTraversal(root->_right);
}

// 后序遍历---左右根
void PostorderTraversal(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	PostorderTraversal(root->_left);
	PostorderTraversal(root->_right);
	printf("%d ", root->_val);
}

// 释放二叉树内存
void FreeBinaryTree(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	FreeBinaryTree(&((*root)->_left));
	FreeBinaryTree(&((*root)->_right));

	free(*root);
	*root = NULL;
}

// 计算二叉树节点总数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

// 查找特定值的节点
BTNode* searchNode(BTNode* root, BTDataType val)
{
	if (root == NULL || root->_val == val) {
		return root;
	}
	if (val < root->_val) {
		return searchNode(root->_left, val);
	}
	else {
		return searchNode(root->_right, val);
	}
}

// 计算二叉树的高度
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftHeight = BinaryTreeHeight(root->_left);
	int rightHeight = BinaryTreeHeight(root->_right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// 计算二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 第k层节点个数
int BinaryTreeLevelSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelSize(root->_left, k - 1) 
		+ BinaryTreeLevelSize(root->_right, k - 1);
}
// 查找特定值的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType val)
{
	if (root == NULL || root->_val == val) {
		return root;
	}

	BTNode* leftfind = BinaryTreeFind(root->_left, val);
	if (leftfind)
	{
		return  leftfind;
	}
	BTNode* rightfind = BinaryTreeFind(root->_right, val);
	if (rightfind)
	{
		return rightfind;
	}
	return NULL;
}

// 层序遍历
// 借助数据结构队列
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		// 取对头
		BTNode* front = QueueFront(&q);
		// 打印
		printf("%d ", front->_val);
		QueuePop(&q);
		// 对头左右孩子入队列
		if (front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
	QueueDestroy(&q);
}

// 判断⼆叉树是否是完全⼆叉树
// 借助数据结构队列
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}
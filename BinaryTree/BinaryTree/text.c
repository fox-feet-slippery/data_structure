#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

void CreateBinaryTree()
{
	BTNode* root = NULL;
	

	InsertBinaryTreeNode(&root, 50);
	InsertBinaryTreeNode(&root, 30);
	InsertBinaryTreeNode(&root, 70);
	InsertBinaryTreeNode(&root, 20);
	InsertBinaryTreeNode(&root, 40);
	InsertBinaryTreeNode(&root, 60);
	InsertBinaryTreeNode(&root, 90);

	PreorderTraversal(root);
	printf("\n");

	printf("size : %d\n", BinaryTreeSize(root));
	printf("leafsize : %d\n", BinaryTreeLeafSize(root));
	
	printf("k size : %d\n", BinaryTreeLevelSize(root,2));
	printf("hight : %d\n",BinaryTreeHeight(root));
	printf("%p\n",BinaryTreeFind(root, 99));

	LevelOrder(root);
	printf("\n");
	printf("%d\n", BinaryTreeComplete(root));
	FreeBinaryTree(&root);
}


int main()
{
	CreateBinaryTree();

	return 0;
}
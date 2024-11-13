#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int BTDataType;

// ⼆叉链
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left; // 指向当前结点左孩⼦
	struct BinaryTreeNode* _right; // 指向当前结点右孩⼦
	BTDataType _val; // 当前结点值域
}BTNode;

// 创建新节点
BTNode* CreateBinaryTreeNode(BTDataType val);

// 插入节点
void InsertBinaryTreeNode(BTNode** root, BTDataType val);

// 前序遍历
void PreorderTraversal(BTNode* root);

// 中序遍历
void InorderTraversal(BTNode* root);

// 后序遍历
void PostorderTraversal(BTNode* root);

// 释放二叉树内存
void FreeBinaryTree(BTNode** root);

// 计算二叉树节点总数
int BinaryTreeSize(BTNode* root);

// 查找特定值的节点
BTNode* searchNode(BTNode* root, BTDataType val);

// 计算二叉树的高度
int BinaryTreeHeight(BTNode* root);

// 计算二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);

// 第k层节点个数
int BinaryTreeLevelSize(BTNode* root, int k);

// 查找特定值的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType val);

// 层序遍历
void LevelOrder(BTNode* root);

// 判断⼆叉树是否是完全⼆叉树
bool BinaryTreeComplete(BTNode* root);

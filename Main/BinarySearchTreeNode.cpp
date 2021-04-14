#include "BinarySearchTreeNode.h"

BinarySearchTreeNode::BinarySearchTreeNode(int key)
{
	this->key = key;
	this->Left = nullptr;
	this->Right = nullptr;
}

BinarySearchTreeNode* BinarySearchTreeNode::GetLeftNode()
{
	return this->Left;
}

BinarySearchTreeNode* BinarySearchTreeNode::GetRightNode()
{
	return this->Right;
}

int BinarySearchTreeNode::GetKey()
{
	return this->key;
}

void BinarySearchTreeNode::SetLeftNode(BinarySearchTreeNode* leftNode)
{
	this->Left = leftNode;
}

void BinarySearchTreeNode::SetRightNode(BinarySearchTreeNode* rightNode)
{
	this->Right = rightNode;
}

BinarySearchTreeNode::~BinarySearchTreeNode()
{
	delete this->Right;
	delete this->Left;
}
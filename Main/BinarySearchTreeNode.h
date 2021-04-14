#pragma once
class BinarySearchTreeNode
{
public:
	BinarySearchTreeNode(int key);
	BinarySearchTreeNode* GetLeftNode();
	BinarySearchTreeNode* GetRightNode();
	int GetKey();
	void SetLeftNode(BinarySearchTreeNode* leftNode);
	void SetRightNode(BinarySearchTreeNode* rightNode);

	~BinarySearchTreeNode();

private:
	int key;
	BinarySearchTreeNode* Left;
	BinarySearchTreeNode* Right;
};


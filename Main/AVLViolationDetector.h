#pragma once
#include "BinarySearchTree.h"

class AVLViolationDetector
{
public:
	BinarySearchTree* GetBST();
	void SetBST(BinarySearchTree* bst);
	AVLViolationDetector(BinarySearchTree* bst);
	int CalculateAndPrintViolation(BinarySearchTreeNode* bTreeNode);
private:
	BinarySearchTree* bst;
};


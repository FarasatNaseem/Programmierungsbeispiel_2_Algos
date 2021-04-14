#include "AVLViolationDetector.h"

BinarySearchTree* AVLViolationDetector::GetBST()
{
	return this->bst;
}

AVLViolationDetector::AVLViolationDetector(BinarySearchTree* bst)
{
	this->bst = bst;
	this->bst->SetMinNode(this->bst->head->GetKey());
	this->bst->SetMaxNode(this->bst->head->GetKey());
}

void AVLViolationDetector::SetBST(BinarySearchTree* bst)
{
	this->bst = bst;
}

int AVLViolationDetector::CalculateAndPrintViolation(BinarySearchTreeNode* bTreeNode)
{
	int rightSide = 0;
	int leftSide = 0;

	if (bTreeNode != nullptr)
	{
		if (bTreeNode->GetKey() < this->bst->GetMinNode())
			this->bst->SetMinNode(bTreeNode->GetKey());

		if (bTreeNode->GetKey() > this->bst->GetMaxNode())
			this->bst->SetMaxNode(bTreeNode->GetKey());

		this->bst->SetSumOfAllNodes(this->bst->GetSumOfAllNodes() + bTreeNode->GetKey());
		this->bst->SetTotalNodes(this->bst->GetTotalNodes() + 1);

		
		rightSide = this->CalculateAndPrintViolation(bTreeNode->GetRightNode());
		leftSide = this->CalculateAndPrintViolation(bTreeNode->GetLeftNode());

		int result = rightSide - leftSide;

		if (result < -1 || result > 1)
		{
			this->bst->SetIsAVL(false);

			std::cout << "bal(" << bTreeNode->GetKey() << ")" << " = " << result << " (AVL violation!)" << std::endl;
		}
		else
		{
			std::cout << "bal(" << bTreeNode->GetKey() << ")" << " = " << result << std::endl;
		}

		//Print(bTreeNode->GetKey(), rightSide - leftSide);

		if (rightSide > leftSide)
		{
			return 1 + rightSide;
		}

		return 1 + leftSide;
	}

	return rightSide - leftSide;
}

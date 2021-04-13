#include "BinarySearchTree.h"

float avg = 0.0;
int sumOfNum = 0;
int totalNodes = 0;
int min = 0;
int max = 0;
bool isAvl = true;

void Print(int key, int result)
{
	if (result < -1 || result > 1)
	{
		isAvl = false;
		std::cout << "bal(" << key << ")" << " = " << result << " (AVL violation!)" << std::endl;
	}
	else
	{
		std::cout << "bal(" << key << ")" << " = " << result << std::endl;
	}
}

int CalculateViolationAndPrint(BinarySearchTreeNode* bTreeNode)
{
	int rightSide = 0;
	int leftSide = 0;

	if (bTreeNode != nullptr)
	{
		rightSide = CalculateViolationAndPrint(bTreeNode->GetRightNode());
		leftSide = CalculateViolationAndPrint(bTreeNode->GetLeftNode());
		
		if (bTreeNode->GetKey() < min)
			min = bTreeNode->GetKey();

		if (bTreeNode->GetKey() > max)
			max = bTreeNode->GetKey();

		sumOfNum += bTreeNode->GetKey();
		totalNodes++;

		Print(bTreeNode->GetKey(), rightSide - leftSide);

		if (rightSide > leftSide)
		{
			return 1 + rightSide;
		}

		return 1 + leftSide;
	}

	return rightSide - leftSide;
}

float CalculateAvg(int sumOfNodeValues, int totalNodes)
{
	return (float)sumOfNodeValues / (float)totalNodes;
}

int main()
{
	BinarySearchTree* binarySearchTree = new BinarySearchTree();

	// Loading data from file.
	binarySearchTree->Load("./Data.csv");

	if (binarySearchTree->head != nullptr)
	{
		min = binarySearchTree->head->GetKey();
		max = binarySearchTree->head->GetKey();
	}

	int heightOfTree = CalculateViolationAndPrint(binarySearchTree->head);

	// Calculating avg
	avg = CalculateAvg(sumOfNum, totalNodes);

	if (isAvl)
		std::cout << "AVL: yes";
	else
		std::cout << "AVL: no";

	std::cout << "\nMIN: " << min << " MAX: " << max << " AVG: " << avg << std::endl;
}

#include "BinarySearchTree.h"

/*
----------------Binary search tree-------------------

	5,3,10,15,22

		 5
		/ \
	   3   10
			\
			15
			 \
			 22

*/

float avg = 0.0;
static int sumOfNum = 0;
static int totalNodes = 0;
int min = 0;
int max = 0;
static bool isAvl = true;

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

void CalculateAndPrintBalanceFactor(BinarySearchTreeNode* bTreeNode)
{
	int leftSideCounter = 0;
	int rightSideCounter = 0;

	if (bTreeNode != nullptr)
	{
		sumOfNum += bTreeNode->GetKey();
		totalNodes++;

		if (bTreeNode->GetRightNode() != nullptr)
		{
			if (bTreeNode->GetRightNode()->GetRightNode() != nullptr)
			{
				if (bTreeNode->GetRightNode()->GetLeftNode() != nullptr)
				{
					rightSideCounter += 3;
				}
				else
				{
					rightSideCounter += 2;
				}
			}
			else
			{
				rightSideCounter++;
			}
		}

		if (bTreeNode->GetLeftNode() != nullptr)
		{
			if (bTreeNode->GetLeftNode()->GetRightNode() != nullptr)
			{
				if (bTreeNode->GetLeftNode()->GetLeftNode() != nullptr)
				{
					leftSideCounter += 3;
				}
				else
				{
					leftSideCounter += 2;
				}
			}
			else
			{
				leftSideCounter++;
			}
		}
	}

	Print(bTreeNode->GetKey(), rightSideCounter - leftSideCounter);

	if (bTreeNode->GetLeftNode() != nullptr && bTreeNode->GetRightNode() != nullptr)
	{
		//     Calculating min and max
		/*-----------------------------------------*/
		if (bTreeNode->GetLeftNode()->GetKey() < min)
			min = bTreeNode->GetLeftNode()->GetKey();

		if (bTreeNode->GetRightNode()->GetKey() < min)
			min = bTreeNode->GetRightNode()->GetKey();

		if (bTreeNode->GetLeftNode()->GetKey() > max)
			max = bTreeNode->GetLeftNode()->GetKey();

		if (bTreeNode->GetRightNode()->GetKey() > max)
			max = bTreeNode->GetRightNode()->GetKey();
		/*-----------------------------------------*/

		CalculateAndPrintBalanceFactor(bTreeNode->GetRightNode());
		CalculateAndPrintBalanceFactor(bTreeNode->GetLeftNode());
	}

	if (bTreeNode->GetLeftNode() != nullptr && bTreeNode->GetRightNode() == nullptr)
	{
		//     Calculating min and max

		/*-----------------------------------------*/
		if (bTreeNode->GetLeftNode()->GetKey() < min)
			min = bTreeNode->GetLeftNode()->GetKey();

		if (bTreeNode->GetLeftNode()->GetKey() > max)
			max = bTreeNode->GetLeftNode()->GetKey();
		/*-----------------------------------------*/

		CalculateAndPrintBalanceFactor(bTreeNode->GetLeftNode());
	}

	if (bTreeNode->GetRightNode() != nullptr && bTreeNode->GetLeftNode() == nullptr)
	{
		//     Calculating min and max

		/*-----------------------------------------*/
		if (bTreeNode->GetRightNode()->GetKey() < min)
			min = bTreeNode->GetRightNode()->GetKey();

		if (bTreeNode->GetRightNode()->GetKey() > max)
			max = bTreeNode->GetRightNode()->GetKey();
		/*-----------------------------------------*/

		CalculateAndPrintBalanceFactor(bTreeNode->GetRightNode());
	}
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

	// min value = node 0 of tree
	// max value = node 0 of tree
	if (binarySearchTree->head != nullptr)
	{
		min = binarySearchTree->head->GetKey();
		max = binarySearchTree->head->GetKey();
	}

	//Print(binarySearchTree);
	CalculateAndPrintBalanceFactor(binarySearchTree->head);

	// Calculating avg
	avg = CalculateAvg(sumOfNum, totalNodes);

	if (isAvl)
		std::cout << "AVL yes";
	else
		std::cout << "AVL no";

	std::cout << "\nMIN: " << min << " MAX: " << max << " AVG: " << avg << std::endl;
}

#include "BinarySearchTree.h"
#include "AVLViolationDetector.h"

float CalculateAvg(int sumOfNodeValues, int totalNodes)
{
	return (float)sumOfNodeValues / (float)totalNodes;
}

int main()
{
	BinarySearchTree* binarySearchTree = new BinarySearchTree();
	binarySearchTree->Load("./Data.csv");
	AVLViolationDetector* avlViolationDetector = new AVLViolationDetector(binarySearchTree);
	int bstNodeHeight = avlViolationDetector->CalculateAndPrintViolation(binarySearchTree->head);
	
	float avg = CalculateAvg(binarySearchTree->GetSumOfAllNodes(), binarySearchTree->GetTotalNodes());

	if (binarySearchTree->GetIsAVL())
		std::cout << "AVL: yes";
	else
		std::cout << "AVL: no";

	std::cout << "\nMIN: " << binarySearchTree->GetMinNode() << " MAX: " << binarySearchTree->GetMaxNode() << " AVG: " << avg << std::endl;
	
	delete binarySearchTree;
	delete avlViolationDetector;
}

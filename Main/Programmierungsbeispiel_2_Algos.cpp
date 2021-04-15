#include "BinarySearchTreeNode.cpp"
#include "BinarySearchTree.cpp"
#include "AVLViolationDetector.cpp"

float CalculateAvg(int sumOfNodeValues, int totalNodes)
{
	return (float)sumOfNodeValues / (float)totalNodes;
}

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cout << "\nno arguments\n";
		return 0;
	}
	BinarySearchTree *binarySearchTree = new BinarySearchTree();
	binarySearchTree->Load(std::string(argv[1]));
	AVLViolationDetector *avlViolationDetector = new AVLViolationDetector(binarySearchTree);

	int bstNodeHeight = avlViolationDetector->CalculateAndPrintViolation(binarySearchTree->head);

	float avg = CalculateAvg(binarySearchTree->GetSumOfAllNodes(), binarySearchTree->GetTotalNodes());

	if (binarySearchTree->GetIsAVL())
		std::cout << "AVL: yes";
	else
		std::cout << "AVL: no";

	std::cout << "\nMIN: " << binarySearchTree->GetMinNode() << " MAX: " << binarySearchTree->GetMaxNode() << " AVG: " << avg << std::endl;

	if (argc >= 2)
	{
		std::cout << "\nSearch:\n";
		BinarySearchTree *target = new BinarySearchTree();
		target->Load(std::string(argv[2]));
		if (target->head->GetLeftNode() == nullptr && target->head->GetRightNode() == nullptr)
		{
			//search for single node
			std::list<int> *path = binarySearchTree->SearchInt(target->head->GetKey());
			if (path != nullptr) //target found
			{
				std::cout << path->back() << " found";
				bool first = true;
				for (auto i = path->begin(); i != path->end(); i++)
				{
					if (first)
					{
						std::cout << " ,";
						first = false;
					}
					std::cout << *i;
				}
				delete path;
			}
			else //target not found
			{
				std::cout << target->head->GetKey() << " not found" << std::endl;
			}
		}
		delete target;
	}

	delete binarySearchTree;
	delete avlViolationDetector;
}

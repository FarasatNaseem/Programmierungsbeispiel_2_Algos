#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	this->head = nullptr;
	this->isAVL = true;
	this->sumOfAllNodes = 0;
	this->totalNodes = 0;
	this->min = 0;
	this->max = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	delete this->head;
}

void BinarySearchTree::Load(std::string file)
{
	std::ifstream myfile(file);

	int key;
	std::string string_key;

	if (myfile.is_open())
	{
		while (true)
		{
			string_key = "";

			getline(myfile, string_key);

			if (string_key.empty())
				break;

			try
			{
				key = stoi(string_key);
				head = Insert(head, key);
			}
			catch (const char *msg)
			{
				std::cerr << msg << '\n';
				break;
			}
		}

		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}
}

BinarySearchTreeNode *BinarySearchTree::Insert(BinarySearchTreeNode *head, int key)
{
	if (head == nullptr)
		head = new BinarySearchTreeNode(key);

	if (head->GetLeftNode() != nullptr)
		if (head->GetLeftNode()->GetKey() == key)
			return head;

	if (head->GetRightNode() != nullptr)
		if (head->GetRightNode()->GetKey() == key)
			return head;

	if (key > head->GetKey())
		head->SetRightNode(Insert(head->GetRightNode(), key));
	else if (key < head->GetKey())
		head->SetLeftNode(Insert(head->GetLeftNode(), key));

	return head;
}

int BinarySearchTree::GetMinNode()
{
	return this->min;
}

int BinarySearchTree::GetMaxNode()
{
	return this->max;
}

int BinarySearchTree::GetTotalNodes()
{
	return this->totalNodes;
}

int BinarySearchTree::GetSumOfAllNodes()
{
	return this->sumOfAllNodes;
}

bool BinarySearchTree::GetIsAVL()
{
	return this->isAVL;
}

void BinarySearchTree::SetMinNode(int min)
{
	this->min = min;
}

void BinarySearchTree::SetMaxNode(int max)
{
	this->max = max;
}

void BinarySearchTree::SetTotalNodes(int totalNodes)
{
	this->totalNodes = totalNodes;
}

void BinarySearchTree::SetSumOfAllNodes(int sumOfAllNodes)
{
	this->sumOfAllNodes = sumOfAllNodes;
}

void BinarySearchTree::SetIsAVL(bool isAVL)
{
	this->isAVL = isAVL;
}

//search for a single integer & return the path from root to target as a list (return null if not found)
std::list<int> *BinarySearchTree::SearchInt(int target)
{
	auto rv = new std::list<int>();
	if (this->rSearchInt(target, this->head, rv))
		return rv;
	else
	{
		delete rv;
		return nullptr;
	}
}

//recursive loop to target int
bool BinarySearchTree::rSearchInt(int target, BinarySearchTreeNode *currNode, std::list<int> *path)
{
	path->push_back(currNode->GetKey());
	if (target == currNode->GetKey())
	{
		return true;
	}
	else
	{
		if (target > currNode->GetKey() && currNode->GetRightNode() != nullptr)
			return rSearchInt(target, currNode->GetRightNode(), path);
		else if (target < currNode->GetKey() && currNode->GetLeftNode() != nullptr)
			return rSearchInt(target, currNode->GetLeftNode(), path);
		else
			return false;
	}
}

bool BinarySearchTree::SearchSubTree(BinarySearchTree *target)
{
	return rSearchSubTree(this->head, target->head, false);
}

bool BinarySearchTree::rSearchSubTree(BinarySearchTreeNode *current, BinarySearchTreeNode *comp, bool prevMatch)
{
	if (comp == nullptr) //ende des gesuchten baumes erreicht
	{
		if (current == nullptr) //wenn der hauptbaum auch aus ist -> true
			return true;
		else
			return false;
	}
	else if (current == nullptr) //knoten der im gesuchten Baum vorhanden ist, existiert im hauptbaum nicht
		return false;

	if (current->GetKey() == comp->GetKey())
	{
		return rSearchSubTree(current->GetLeftNode(), comp->GetLeftNode(), true) && rSearchSubTree(current->GetRightNode(), comp->GetRightNode(), true);

	}
	else if (prevMatch == false) //Unterschied nach einer Übereinstimmung -> suche kann abgebrochen werden
	{
		if (current->GetKey() > comp->GetKey())
			return rSearchSubTree(current->GetLeftNode(), comp, false);
		else
			return rSearchSubTree(current->GetRightNode(), comp, false);
	}
	else
	{
		return false;
	}
}

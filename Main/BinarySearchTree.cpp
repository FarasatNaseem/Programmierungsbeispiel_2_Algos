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
			catch (const char* msg)
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

BinarySearchTreeNode* BinarySearchTree::Insert(BinarySearchTreeNode* head, int key)
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

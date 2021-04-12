#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	head = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	delete this->head;
}

void BinarySearchTree::Load()
{
	std::ifstream myfile("./Data.csv");

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
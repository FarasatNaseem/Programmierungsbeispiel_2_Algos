#pragma once
#include "BinarySearchTreeNode.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	void Load();
	BinarySearchTreeNode* head;

private:
	BinarySearchTreeNode* Insert(BinarySearchTreeNode* head, int key);
};


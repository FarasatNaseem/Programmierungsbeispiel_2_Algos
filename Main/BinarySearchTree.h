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
	void Load(std::string file);
	BinarySearchTreeNode* head;
	int GetMinNode();
	int GetMaxNode();
	int GetTotalNodes();
	int GetSumOfAllNodes();
	bool GetIsAVL();
	void SetMinNode(int min);
	void SetMaxNode(int max);
	void SetTotalNodes(int totalNodes);
	void SetSumOfAllNodes(int sumOfAllNodes);
	void SetIsAVL(bool isAVL);

private:
	BinarySearchTreeNode* Insert(BinarySearchTreeNode* head, int key);
	int min;
	int max;
	int totalNodes;
	int sumOfAllNodes;
	bool isAVL;
};


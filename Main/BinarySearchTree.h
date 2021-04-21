#pragma once
#include "BinarySearchTreeNode.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <list>

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	void Load(std::string file);
	BinarySearchTreeNode *head;
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
	std::list<int> *SearchInt(int target);
	bool SearchSubTree(BinarySearchTree *target);

private:
	BinarySearchTreeNode *Insert(BinarySearchTreeNode *head, int key);
	bool rSearchInt(int target, BinarySearchTreeNode *startNode, std::list<int> *path);
	bool rSearchSubTree(BinarySearchTreeNode *currentNode, BinarySearchTreeNode *comp, bool prevMatch);
	int min;
	int max;
	int totalNodes;
	int sumOfAllNodes;
	bool isAVL;
};

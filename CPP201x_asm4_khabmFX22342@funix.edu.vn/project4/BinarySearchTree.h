#pragma once
#include "Setting.h"
#include "Car.h"
#include <vector>

class Node {
public:
	Car* value;
	Node* left;
	Node* right;
	Node(Car* data) {
		value = data;
		left = NULL;
		right = NULL;
	}
};

class BST {
private:
	Node* root;
	int count = 0;
	int index = 0;
	void Insert(Car* data, Node* aNode);
	Node* Search(string key, Node* aNode);
	void WriteDataToStorage(Node* aNode);
	void P_Display(Node* aNode);
	void P_Sound(Node* aNode);
	void P_General(Node* aNode);
	void P_All(Node* aNode);
public:
	BST();
	int Size();
	void Insert(Car* data);
	Node* Search(string key);
	void OverWrite(Car* data);
	void LoadDataFromStorage();
	void WriteDataToStorage();
	void Print(int i);
};
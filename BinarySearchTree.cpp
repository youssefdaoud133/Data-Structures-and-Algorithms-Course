// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int idata)
{
	struct node* node = new struct node;
	node->data = idata;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

void InsertArrayToBinaryTree (int x ,node * CurNode ) {
	

		if (x < CurNode->data) {
			if (CurNode->left != nullptr) {
				InsertArrayToBinaryTree(x, CurNode->left);
			}
			else {
				CurNode->left = newNode(x);
			}

		}
		else {
			if (CurNode->right != nullptr) {
				InsertArrayToBinaryTree(x, CurNode->right);
			}
			else {
				CurNode->right = newNode(x);
			}
		}
	

};

bool FindByBinarySearch(int F , node* CurNode) {
	if (F == CurNode->data) {
		return 1;
	}
	if (F < CurNode->data) {
		if (CurNode->left != nullptr) {
			return FindByBinarySearch(F, CurNode->left);
		}
		else {
			return 0;
		}
	}
	if (F > CurNode->data) {

		if (CurNode->right != nullptr) {
			return FindByBinarySearch(F, CurNode->right);
		}
		else {
			return 0;
		}

	}


}

int main()
{
	int arr[12] = { 12, 9, 5, 7, 10, 11, 18, 13, 16, 80, 55, 100 };
	struct node* root = newNode(arr[0]);
	for (int i = 1; i < sizeof(arr); i++) {
		InsertArrayToBinaryTree(arr[i], root);
	}
	cout<<FindByBinarySearch(100, root);
	

    
}


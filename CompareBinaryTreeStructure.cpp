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

int e = 0;

void CompareStructure(node * Root, node* Root2 ) {
	node* left = Root->left;
	node* right = Root->right;
	node* left2 = Root2->left;
	node* right2 = Root2->right;

	if ((left != nullptr && left2 != nullptr) || (left == nullptr && left2 == nullptr)) {
		if(left != nullptr){
			 CompareStructure(left, left2);
		}
		
		
	}
	else {
		e++;
	}

	if ((right != nullptr && right2 != nullptr)|| (right == nullptr && right2 == nullptr)) {
		if (right != nullptr) {
			CompareStructure(right, right2);
		}

	}
	else
	{
		e++;
	}

}
void mastercompare(node* Root, node* Root2) {
	CompareStructure(Root , Root2);
	if (e != 0) {
		cout << "not identical";
	}
	else
	{
		cout << "identical";


	}
}


int main()
{
	int arr[13] = { 1,12, 9, 5, 7, 10,9, 11, 18, 13, 16, 55, 100 };
	struct node* root = newNode(arr[0]);
	for (int i = 1; i < 13; i++) {
		InsertArrayToBinaryTree(arr[i], root);
	}
	int arr2[13] = { 1,12, 9, 5, 7, 10,9, 11, 18, 13, 16, 55, 100 };
	struct node* root2 = newNode(arr2[0]);
	for (int i = 1; i < 12; i++) {
		InsertArrayToBinaryTree(arr2[i], root2);
	}
	//cout<<FindByBinarySearch(100, root);
	mastercompare(root, root2);
	

    
}


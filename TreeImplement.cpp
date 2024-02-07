
#include<iostream>
#include <string>
#include <cctype>
using namespace std;
bool isNumeric(const std::string& str) {
	for (char c : str) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
	return true;
}

struct node
{
	string data;
	struct node* left;
	struct node* right;
};

struct node* newNode(string idata)
{
	struct node* node = new struct node;
	node->data = idata;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int Process(int Left , int Right, string Operator ) {
	if(Operator == "+") {
		return Left + Right;
	}if(Operator == "-") {
		return Left - Right;
	}if(Operator == "*") {
		return Left * Right;
	}if(Operator == "/") {
		return Left / Right;
	}
}
int TreeBinaryEquation(node* SupTree) {
	int left;
	int right;
	
	if (isNumeric(SupTree->data)) {
		return stoi(SupTree->data);
	}
	left = TreeBinaryEquation(SupTree->left);
	right = TreeBinaryEquation(SupTree->right);
	return Process(left,right, SupTree->data);

	
}

int main()
{
	
	struct node* root = newNode("+");
	root->left = newNode("*");
	root->left->left = newNode("2");
	root->left->right = newNode("-");
	root->left->right->left = newNode("10");
	root->left->right->right = newNode("7");
	root->right = newNode("+");
	root->right->left = newNode("3");
	root->right->right = newNode("*");
	root->right->right->left = newNode("2");
	root->right->right->right = newNode("4");
	
	

	cout<<TreeBinaryEquation(root);
	
	return 0;
}
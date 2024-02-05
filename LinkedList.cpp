// difference between array and linked list
// array all element in series in memory e1 -> e2 -> e3
// linked list  all element not in series in memory e1 ------> e2 ---> e3 -> e4  <---e5
// in linked list its easy to insert first element 

#include <algorithm>
#include <iostream>
using namespace std;



class Node {
private:
	int data;
	Node* next;
public:
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
	int GetData() {
		return this->data;
	}
	void SetData(int data) {
		this->data = data;
	}
	void SetNext(Node* next) {
		this->next = next;
	}
	Node* GetNext() {
		return this->next;
	}

	// 
	friend class LinkedList;


};


class LinkedList {
private:
	Node* Head;
	Node* tail;
	
public:
	LinkedList(){
		this->Head = nullptr;		 
	}
	bool embty() {
		if (this->Head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	
	void push(int d) {
		Node* n = new Node(d);
		n->SetNext(this->Head);
		this->Head = n;
		

	}

	int length() {
		Node* CurNode = Head;
		int length = 0;
		while (CurNode != nullptr)
		{
			length++;
			CurNode = CurNode->GetNext();
		}

		return length;

	}
	void PopFront() {
		Node* temp = this->Head;
		if (this->embty()) {
			return;
		}
		else
		{

		this->Head = (this->Head->GetNext());
		delete temp;
		}

	}


	
	void PushBack(int d) {
		Node* n = new Node(d);
		if (this->Head == nullptr) {
			this->Head = n;
			
		}
		else
		{
			Node* CurNode = Head;
			
			while (CurNode->GetNext() != nullptr)
			{
				CurNode = CurNode->GetNext();
			}
			CurNode->SetNext(n);


			
			

		}
		
	}
	void PopBack() {
		if (this->embty()) {
			return;
		}
		if (this->Head->GetNext() == nullptr) {
			delete Head;
			this->Head = nullptr;
			return;
		}

		Node* LastNode = Head;
		Node* PreLastNode = nullptr;
		while (LastNode ->GetNext() != nullptr)
		{
			PreLastNode=(LastNode);
			LastNode = LastNode->GetNext();
		}
		delete LastNode;
		PreLastNode->SetNext(nullptr);

	}
	void Clear(){
		while (! this->embty()) {
			this->PopFront();
		}
	}
	int GetIndex(int index) {
		if (index < 0 || index >= length()) {
			cout << "Index out of bounds." << endl;
			return -1;  // or throw an exception, depending on your design choice
		}

		Node* FirstElement = Head;
		for (int i = 0; i < index; i++) {
			FirstElement = FirstElement->GetNext();
		}

		return FirstElement->GetData();
	}

	~LinkedList()
	{
		this->Clear();	
	}
};



int main()

{
	LinkedList * L1 = new LinkedList;
	cout << L1->length()<<endl;
	L1->push(5);
	L1->push(6);
	L1->push(4);
	L1->PushBack(7);
	cout << L1->length()<<endl;
	cout << L1->GetIndex(3)<<endl;
	cout << L1->GetIndex(2)<<endl;
	L1->PopBack();
	cout << L1->GetIndex(3)<<endl;
	cout << L1->length()<<endl;
	cout << L1->embty() << endl;
	delete L1;





	
	return 0;
	
}


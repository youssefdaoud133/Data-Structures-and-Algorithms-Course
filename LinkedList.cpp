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
	int power;
	Node* next;
public:
	Node(int data , int power) {
		this->data = data;
		this->power = power;
		this->next = nullptr;
	}Node(int data) {
		this->data = data;
		this->power = 0;
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
	// with power
	void PushBackWithPower(int d , int p) {
		Node* n = new Node(d,p);
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
	void SetIndex(int index,int data) {
		if (index < 0 || index >= length()) {
			cout << "Index out of bounds." << endl;
			  // or throw an exception, depending on your design choice
		}

		Node* FirstElement = Head;
		for (int i = 0; i < index; i++) {
			FirstElement = FirstElement->GetNext();
		}

		 FirstElement->SetData(data);
	}
	void pop(int index) {
		if (index < 0 || index >= length()) {
			cout << "Index out of bounds." << endl;
			  // or throw an exception, depending on your design choice
		}

		Node* PrePopElement = nullptr;
		Node* FirstElement = Head;
		for (int i = 0; i < index; i++) {
			PrePopElement = FirstElement;
			FirstElement = FirstElement->GetNext();
		
			
		}
		PrePopElement->SetNext(FirstElement->GetNext());
		delete FirstElement;

		
	}
	void SelectionSort() {
		LinkedList * SortedLinkedList = new LinkedList;
		int length = this->length();
		for (int i = 0; i < length; i++) {
			int min = this->GetIndex(i);
			int popindex = this->GetIndex(i);
			for (int j = i+1; j < length; j++) {
				if (this->GetIndex(j) < this->GetIndex(i)) {
					int temp_data = this->GetIndex(i);
					this->SetIndex(i, this->GetIndex(j)) ;
					this->SetIndex(j, temp_data) ;
				}
			}

		}
	}
	void InitializeFromArr(int arr [], int length) {
		for (int i = 0; i < length; i++) {
			this->PushBackWithPower(arr[i], length - (i + 1));
		}
	}
	void InsertNode(Node * InsertNodeAfterThisNode,int d) {
		Node* n = new Node(d);
		n->SetNext(InsertNodeAfterThisNode->GetNext());
		InsertNodeAfterThisNode->SetNext(n);
	}

	void completes() {
		Node* ptrtomove = this->Head;
		while(ptrtomove->GetNext() != nullptr){
			if((ptrtomove->GetData() +1) == ptrtomove->GetNext()->GetData()){
				ptrtomove = ptrtomove->GetNext();
				continue;
			}
			this->InsertNode(ptrtomove, ptrtomove->GetData() + 1);
			ptrtomove = ptrtomove->GetNext();
			
		}

	}

	~LinkedList()
	{
		this->Clear();	
	}
};



int main()

{	
	int arr[3] = { 2,5,7 };
	LinkedList * L1 = new LinkedList;
	L1->InitializeFromArr(arr, 3);
	L1->completes();
	cout << L1->length() << endl;
	for (int i = 0; i < L1->length(); i++) {

	cout<<L1->GetIndex(i)<<endl;
	}

	







	
	return 0;
	
}


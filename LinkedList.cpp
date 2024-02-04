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



};



int main()

{
	Node index1(6);
	Node index2(70);
	index1.SetNext(&index2);
	Node index3(80);
	index2.SetNext(&index3);
	cout << (index1.GetNext()->GetData());


	
	return 0;
	
}


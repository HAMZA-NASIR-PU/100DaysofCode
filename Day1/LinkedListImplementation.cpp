#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	void deleteLinkedList(Node* node) {
		if (node == nullptr) {
			return;
		}
		deleteLinkedList(node->next);
		delete node;
		node = nullptr;
	}
public:
	LinkedList() {
		this->head = this->tail = nullptr;
	}

	void insertAtEnd(Node* node) {
		if (!this->head) {
			this->head = new Node(node->data);
			this->tail = this->head;
		}
		else
		{
			this->tail->next = new Node(node->data);
			this->tail = this->tail->next;
		}
	}

	void insertAtEnd(int data) {
		if (!this->head) {
			this->head = new Node(data);
			this->tail = this->head;
		}
		else
		{
			this->tail->next = new Node(data);
			this->tail = this->tail->next;
		}
	}

	void insertAtHead(Node* node) {
		if (!this->head) {
			this->head = new Node(node->data);
			this->tail = this->head;
		}
		else
		{
			Node* n1 = new Node(node->data);
			n1->next = this->head;
			this->head = n1;
		}
	}

	void insertAtHead(int data) {
		if (!this->head) {
			this->head = new Node(data);
			this->tail = this->head;
		}
		else
		{
			Node* n1 = new Node(data);
			n1->next = this->head;
			this->head = n1;
		}
	}

	bool isEmpty() {
		return this->head == nullptr ? true : false;
	}

	bool deleteAtHead() {
		if (this->head) {
			if (this->head == this->tail) {
				delete this->head;
				this->head = this->tail = nullptr;
			}
			else
			{
				Node* n1 = this->head;
				this->head = this->head->next;
				delete n1;
			}
			return true;
		}
		return false;
	}

	bool deleteAtEnd() {
		if (this->head) {
			if (this->head == this->tail) {
				delete this->head;
				this->head = this->tail = nullptr;
			}
			else
			{
				Node* n1 = this->head;

				while (n1->next != this->tail) {
					n1 = n1->next;
				}

				delete n1->next;
				n1->next = nullptr;
				this->tail = n1;
				return true;
			}
		}
		return false;
	}

	bool deleteData(int data) {
		if (this->head) {
			Node* n1 = new Node(99999);
			n1->next = this->head;
			Node* n2 = this->head;
			Node* n3 = n1;

			while (n2) {

				if (n2->data == data) {
					n1->next = n2->next;
					n2->next = nullptr;
					delete n2;
					this->head = n3->next;
					return true;
				}

				n1 = n2;
				n2 = n2->next;
			}
		}
		return false;
	}

	void printLinkedList() {
		if (this->head) {
			Node* n1 = this->head;
			while (n1) {
				cout << n1->data << " ";
				n1 = n1->next;
			}
		}
	}

	~LinkedList() {
		if (this->head) {
			deleteLinkedList(this->head);
			this->head = nullptr;
			this->tail = nullptr;
		}
	}
};


int main() {
	LinkedList l1;
	l1.insertAtEnd(1);
	l1.insertAtEnd(2);
	l1.insertAtEnd(3);
	l1.insertAtEnd(4);
	l1.insertAtEnd(5);
	l1.insertAtEnd(6);

	l1.printLinkedList();
	/*l1.deleteAtEnd();
	l1.deleteAtEnd();
	l1.deleteAtEnd();
	l1.deleteAtEnd();
	l1.deleteAtEnd();
	l1.deleteAtEnd();
	l1.deleteAtEnd();*/
	//l1.printLinkedList();

}
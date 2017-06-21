
#include <iostream>

using namespace std;

class Stack {

	class Node {
	public:
		int data;
		Node *prev;
		Node *next;
		Node(int num) {
			data = num;
			prev = 0;
			next = 0;
		}
	};

	Node *head;
	Node *tail;
	int size;
public:
	Stack() {
		size = 0;
		head = new Node(0);
		tail = new Node(0);
		head->next = tail;
		tail->prev = head;
	}
	~Stack() {

		for (Node * temp = head->next; temp != tail; temp = temp->next) {
			Node *nextNode = temp->next;
			head->next = nextNode;
			nextNode->prev = head;
			delete temp;
			temp = nextNode->prev;
		}

		delete head;
		delete tail;
	}

	void push(int n) {
		Node *newNode = new Node(n);
		Node *nextNode = head->next;
		nextNode->prev = newNode;
		newNode->next = nextNode;
		head->next = newNode;
		newNode->prev = head;
		size++;
	}

	int pop() {
		if (size > 0) {
			Node *popNode = head->next;
			head->next = popNode->next;
			popNode->next->prev = head;
			int tmp = popNode->data;
			delete popNode;
			size--;
			return tmp;
		}
		else {
			return 0;
		}
	}

	bool isEmpty() {
		return size == 0;
	}
};


class Queue {
public:
	Stack s1;
	Stack s2;

	void enQueue(int n) {
		s1.push(n);
	}

	int deQueue() {

		while (!s1.isEmpty()) {
			s2.push(s1.pop());
		}

		int data = s2.pop();

		while (!s2.isEmpty()) {
			s1.push(s2.pop());
		}

		return data;
	}

};

int main() {

	Queue q;
	int cnt = 0;
	
	for (int i = 0; i < 12; i++) {
		q.enQueue(i);
	}

	for (int i = 0; i < 12; i++) {
		cout << q.deQueue() << endl;
	}

	return 0;
}
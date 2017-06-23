#include <iostream>
#include <ctime>

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

		while (!isEmpty()) {
			Node *popNode = head->next;
			head->next = popNode->next;
			popNode->next->prev = head;
			size--;
			delete popNode;
		}
		delete head;
		delete tail;
	}

	void push(int n) {
		Node *insertNode = new Node(n);
		Node *nextNode = head->next;
		nextNode->prev = insertNode;
		insertNode->next = nextNode;
		head->next = insertNode;
		insertNode->prev = head;
		size++;
	}

	int pop() {
		Node *popNode = head->next;
		head->next = popNode->next;
		popNode->next->prev = head;
		int tmp = popNode->data;
		delete popNode;
		size--;
		return tmp;
	}

	bool isEmpty() {
		return size == 0;
	}

};


int main() {

	clock_t begin, end;
	int max = 10000000;
	
	//start
	begin = clock();
	
	Stack s;
	for (int i = 0; i < max; i++) {
		s.push(i);
	}
	for (int i = 0; i < max; i++) {
		s.pop();
	}
	// end
	end = clock();

	cout << (double)((end - begin) / (double)CLOCKS_PER_SEC) << "s" << endl;


	return 0;
}
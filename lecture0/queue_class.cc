

class Queue {
private:
	int size;
	int *arr;
	int rear;
	int front;

public:
	Queue() {
		size = 16;
		arr = new int[size];
		rear = -1;
		front = 0;
	}

	~Queue() {
		delete[] arr;
	}

	void enqueue(int n) {
		if (rear + 1 == size) {
			int *tmp = new int[size*2];
			for (int i = 0; i < size; i++) {
				tmp[i] = arr[i];
			}
			delete[] arr;
			arr = tmp;
			size *= 2;
		}
		arr[++rear] = n;
	}

	int dequeue() {
		if (!isEmpty()) {
			return arr[front++];
		}
		return -1;
	}

	bool isEmpty() {
		return front == rear + 1;
	}

};


class ListQueue {

	class Node {
	public:

		Node() {
			data = 0;
			next = 0;
			prev = 0;
		}
		Node(int d) {
			data = d;
			next = 0;
			prev = 0;
		}

		int data;
		Node *next;
		Node *prev;
	};

private:
	int size;
	Node *head;
	Node *tail;
public:

	ListQueue() {
		size = 0;
		head = new Node;
		tail = new Node;

		head->next = tail;
		tail->prev = head;

	}

	bool isEmpty() {
		return size == 0;
	}

	void enQueue(int n) {
		size++;
		Node *newNode = new Node(n);
		Node *nextNode = head->next;
		nextNode->prev = newNode;
		newNode->next = nextNode;
		head->next = newNode;
		newNode->prev = head;
	}

	int deQueue() {
		if (!isEmpty()) {
			Node *prevNode = tail->prev;
			tail->prev = prevNode->prev;
			prevNode->prev->next = tail;
			size--;
			int data = prevNode->data;
			delete prevNode;
			return data;
		}
		else
			return -1;
	}



};


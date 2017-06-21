
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
	}

	bool isEmpty() {
		return size == 0;
	}
};
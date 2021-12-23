using namespace std;
template<typename T>
class queue {
public:
	/*Create default queue constructor
	*/
	queue();
	/*Insert the parameter x to the queue
	*para x. This is the given type by user parameter in the function enqueue
	*/
	void enqueue( T x);
	/*Get the front element in the queue
	*return Return the first element in the queue
	*/
	T front();
	/*Delete the front element in the queue
	*return Return the first element in the queue
	*/
	T dequeue();
	/*Check whether the queue is empty or not
	*/
	bool isEmpty();
	

private:
	struct node {
		double money;
		node* next;
	};
	node* head;
	int customer;
	node* tail;

};

template<typename T>
queue<T>::queue() {
	head = nullptr;
	tail = nullptr;
}
template<typename T>
void queue<T>::enqueue(T x) {
	if (!head) {
		head = new node{x,head };
		customer++;
		tail = head;

	}
	else {
		tail->next = new node{ head->money + x,nullptr };
		tail = tail->next;
	}
}
template<typename T>
bool queue<T>::isEmpty() {
	return !tail && !head;
}
template<typename T>
T queue<T>::front() {
	if (isEmpty()) {
		cout << "out";
		exit(1);
	}
	return head->money;
}
template<typename T>
T queue<T>::dequeue() {
	T ret = head->money;
	node* tmp = head;
	head = head->next;
	delete tmp;
	if (!head) {
		tail = nullptr;
	}
	return ret;
}
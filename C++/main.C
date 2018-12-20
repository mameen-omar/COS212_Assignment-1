#include "CircularList.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
using namespace std;

int main(void) {

	cout << "************************\n"
		<< "* Testing CircularList *\n"
		<< "************************\n\n";

	/* Circular List */
	CircularList cList1, cList2;

	// Test output stream operator
	cout << "Outputting cList1\nExpected output: []\n"
		<< "Received output: " << cList1 << endl << endl;

	cout << "Outputting cList2\nExpected output: []\n"
		<< "Received output: " << cList2 << endl << endl;

	// Add items
	cout << "Adding 5 to the front of cList1\n";
	cList1.addToFront(5);
	cout << "Outputting cList1\nExpected output: [5]\n"
		<< "Received output: " << cList1 << endl << endl;

	cout << "Adding 5 to the front of cList1\n";
	cList1.addToFront(2);
	cout << "Outputting cList1\nExpected output: [2,5]\n"
		<< "Received output: " << cList1 << endl << endl;

	cout << "Adding 5 to the front of cList1\n";
	cList1.addToFront(9);
	cout << "Outputting cList1\nExpected output: [9,2,5]\n"
		<< "Received output: " << cList1 << endl << endl;

	cout << "Setting cList2 = cList1\n\n";
	cList2 = cList1;

	cout << "Removing " << cList1.deleteFromBack() << " from back of cList1\n";
	cout << "Outputting cList1\nExpected output: [9,2]\n"
		<< "Received output: " << cList1 << endl << endl;

	cout << "Removing " << cList1.deleteFromBack() << " from back of cList1\n";
	cout << "Outputting cList1\nExpected output: [9]\n"
		<< "Received output: " << cList1 << endl << endl;

	cout << "Removing " << cList1.deleteFromBack() << " from back of cList1\n";
	cout << "Outputting cList1\nExpected output: []\n"
		<< "Received output: " << cList1 << endl << endl;

	cout << "Removing " << cList1.deleteFromBack() << " from back of cList1\n";
	cout << "Outputting cList1\nExpected output: []\n"
		<< "Received output: " << cList1 << endl << endl;

	cout << "Outputting cList1\nExpected output: []\n"
		<< "Received output: " << cList1 << endl << endl;

	cout << "Outputting cList2\nExpected output: [9,2,5]\n"
		<< "Received output: " << cList2 << endl << endl;


	/* Stack */
	cout << "*****************\n"
		<< "* Testing Stack *\n"
		<< "*****************\n\n";

	Stack stack1, stack2;
	cout << "Outputting stack1\nExpected output: []\n"
		<< "Received output: " << stack1 << endl << endl;

	cout << "Outputting stack2\nExpected output: []\n"
		<< "Received output: " << stack2 << endl << endl;

	cout << "Inserting 4 to top of stack1\n";
	stack1.push(4);
	cout << "Outputting stack1\nExpected output: [4]\n"
		<< "Received output: " << stack1 << endl << endl;

	cout << "Inserting 1 to top of stack1\n";
	stack1.push(1);
	cout << "Outputting stack1\nExpected output: [1,4]\n"
		<< "Received output: " << stack1 << endl << endl;

	cout << "Inserting 7 to top of stack1\n";
	stack1.push(7);
	cout << "Outputting stack1\nExpected output: [7,1,4]\n"
		<< "Received output: " << stack1 << endl << endl;

	cout << "Setting stack2 = stack1\n\n";
	stack2 = stack1;

	cout << stack1.pop() << " is removed from the top of the stack\n";
	cout << "Outputting stack1\nExpected output: [1,4]\n"
		<< "Received output: " << stack1 << endl << endl;

	cout << stack1.pop() << " is removed from the top of the stack\n";
	cout << "Outputting stack1\nExpected output: [4]\n"
		<< "Received output: " << stack1 << endl << endl;

	cout << stack1.pop() << " is removed from the top of the stack\n";
	cout << "Outputting stack1\nExpected output: []\n"
		<< "Received output: " << stack1 << endl << endl;

	cout << stack1.pop() << " is removed from the top of the stack\n";
	cout << "Outputting stack1\nExpected output: []\n"
		<< "Received output: " << stack1 << endl << endl;

	cout << "* Here are the stacks *\n\n";

	if(stack1.isEmpty())
		cout << "stack1 is empty\n";
	else
		cout << "stack1 is currently not empty\n";
	cout << "Outputting stack1\nExpected output: []\n"
		<< "Received output: " << stack1 << endl << endl;

	if(stack2.isEmpty())
		cout << "stack2 is empty\n";
	else
		cout << "stack2 is currently not empty\n";
	cout << "Outputting stack2\nExpected output: [7,1,4]\n"
		<< "Received output: " << stack2 << endl << endl;

	cout << "The top element of stack2 is " << stack2.peek() << endl << endl;


	/* Queue */
	cout << "*****************\n"
		<< "* Testing Queue *\n"
		<< "*****************\n\n";

	Queue q1, q2;
	cout << "Outputting q1\nExpected output: []\n"
		<< "Received output: " << q1 << endl << endl;

	cout << "Outputting q2\nExpected output: []\n"
		<< "Received output: " << q2 << endl << endl;

	cout << "Number 5 gets takes his place at the back of the queue\n";
	q1.enqueue(5);
	cout << "Outputting q1\nExpected output: [5]\n"
		<< "Received output: " << q1 << endl << endl;

	cout << "Number 8 takes his place behind 5\n";
	q1.enqueue(8);
	cout << "Outputting q1\nExpected output: [5,8]\n"
		<< "Received output: " << q1 << endl << endl;

	cout << "Number 3 takes his place behind 8\n";
	q1.enqueue(3);
	cout << "Outputting q1\nExpected output: [5,8,3]\n"
		<< "Received output: " << q1 << endl << endl;

	cout << "Setting q2 = q1\n\n";
	q2 = q1;

	cout << "Number " << q1.dequeue() << " gets served and leaves the queue\n";
	cout << "Outputting q1\nExpected output: [8,3]\n"
		<< "Received output: " << q1 << endl << endl;

	cout << "Number " << q1.dequeue() << " gets served and leaves the queue\n";
	cout << "Outputting q1\nExpected output: [3]\n"
		<< "Received output: " << q1 << endl << endl;

	cout << "Number " << q1.dequeue() << " gets served and leaves the queue\n";
	cout << "Outputting q1\nExpected output: []\n"
		<< "Received output: " << q1 << endl << endl;

	cout << "Number " << q1.dequeue() << " gets served and leaves the queue\n";
	cout << "Outputting q1\nExpected output: []\n"
		<< "Received output: " << q1 << endl << endl;

	if(q1.isEmpty())
		cout << "q1 is empty\n";
	else
		cout << "q1 is currently not empty\n";
	cout << "Outputting q1\nExpected output: []\n"
		<< "Received output: " << q1 << endl << endl;

	if(q2.isEmpty())
		cout << "q2 is empty\n";
	else
		cout << "q2 is currently not empty\n";
	cout << "Outputting q2\nExpected output: [5,8,3]\n"
		<< "Received output: " << q2 << endl << endl;

	cout << q2.front() << " is at the front of the queue\n\n";


	/* Deque */
	cout << "*****************\n"
		<< "* Testing Deque *\n"
		<< "*****************\n\n";

	Deque dq1, dq2;
	cout << "Outputting dq1\nExpected output: []\n"
		<< "Received output: " << dq1 << endl << endl;

	cout << "Outputting dq2\nExpected output: []\n"
		<< "Received output: " << dq2 << endl << endl;

	cout << "Number 5 gets takes his place at the back of the queue\n";
	dq1.enqueueBack(5);
	cout << "Outputting dq1\nExpected output: [5]\n"
		<< "Received output: " << dq1 << endl << endl;

	cout << "Number 8 takes his place behind 5\n";
	dq1.enqueueBack(8);
	cout << "Outputting dq1\nExpected output: [5,8]\n"
		<< "Received output: " << dq1 << endl << endl;

	cout << "Number 3 takes his place behind 8\n";
	dq1.enqueueBack(3);
	cout << "Outputting dq1\nExpected output: [5,8,3]\n"
		<< "Received output: " << dq1 << endl << endl;

	cout << "Setting dq2 = dq1\n\n";
	dq2 = dq1;

	cout << "Number 12 jumps infront of the queue\n";
	dq1.enqueueFront(12);
	cout << "Outputting dq1\nExpected output: [12,5,8,3]\n"
		<< "Received output: " << dq1 << endl << endl;

	cout << "Number " << dq1.dequeueBack() << " gets tired of everyone pushing and leaves\n";
	cout << "Outputting dq1\nExpected output: [12,5,8]\n"
		<< "Received output: " << dq1 << endl << endl;

	cout << "Number " << dq1.dequeueFront() << " gets served and leaves the queue\n";
	cout << "Outputting dq1\nExpected output: [5,8]\n"
		<< "Received output: " << dq1 << endl << endl;

	cout << "Number " << dq1.dequeueFront() << " gets served and leaves the queue\n";
	cout << "Outputting dq1\nExpected output: [8]\n"
		<< "Received output: " << dq1 << endl << endl;

	cout << "Number " << dq1.dequeueFront() << " gets served and leaves the queue\n";
	cout << "Outputting dq1\nExpected output: []\n"
		<< "Received output: " << dq1 << endl << endl;

	cout << "Number " << dq1.dequeueFront() << " gets served and leaves the queue\n";
	cout << "Outputting dq1\nExpected output: []\n"
		<< "Received output: " << dq1 << endl << endl;

	cout << "Attempting dequeueBack() on empty queue\n";
	cout << "Number " << dq1.dequeueBack() << " gets served and leaves the queue\n";
	cout << "Outputting dq1\nExpected output: []\n"
		<< "Received output: " << dq1 << endl << endl;

	if(dq1.isEmpty())
		cout << "dq1 is empty\n";
	else
		cout << "dq1 is currently not empty\n";
	cout << "Outputting dq1\nExpected output: []\n"
		<< "Received output: " << dq1 << endl << endl;

	if(dq2.isEmpty())
		cout << "dq2 is empty\n";
	else
		cout << "dq2 is currently not empty\n";
	cout << "Outputting dq2\nExpected output: [5,8,3]\n"
		<< "Received output: " << dq2 << endl << endl;

	return 0;
}

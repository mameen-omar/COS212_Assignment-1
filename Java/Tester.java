/*
	Mohamed Ameen Omar
	u16055323
*/

public class Tester {

	public static void main(String[] args) {

		  CircularList list = new CircularList(), list2;

		  System.out.println("Adding items to front of list");
		  list.addToFront(6); list.addToFront(8); list.addToFront(2);

		  list2 = list.clone();

		  System.out.println("Printing list"); System.out.println(list);

		  System.out.println("Printing list2"); System.out.println(list2);

		  System.out.println("Deleting " + list.deleteFromBack() +
		  " from back of list"); System.out.println("Deleting " +
		  list.deleteFromBack() + " from back of list");

		  System.out.println("Printing list"); System.out.println(list);

		  System.out.println("Printing list2"); System.out.println(list2);



		  Stack s = new Stack(); System.out.println("Here is the stack:\n" + s
		  + "\n");

		  if (s.isEmpty()) { System.out.println("The stack is empty"); } else {
		  System.out.println("The stack is currently not empty"); }

		  System.out.println("Adding items to the stack"); s.push(7);
		  s.push(3); s.push(5); s.push(0); s.push(4);

		  if (s.isEmpty()) { System.out.println("The stack is empty"); } else {
		  System.out.println("The stack is currently not empty"); }

		  System.out.println("The top element is " + s.peek());
		  System.out.println("Here is the stack:\n" + s + "\n");

		  System.out.println("Popping " + s.pop() +
		  " from the top of the stack");
		  System.out.println("Here is the stack:\n" + s + "\n");

		  System.out.println("Popping " + s.pop() +
		  " from the top of the stack");
		  System.out.println("Here is the stack:\n" + s + "\n");

		  System.out.println("Popping " + s.pop() +
		  " from the top of the stack");
		  System.out.println("Here is the stack:\n" + s + "\n");

		  System.out.println("Popping " + s.pop() +
		  " from the top of the stack");
		  System.out.println("Here is the stack:\n" + s + "\n");

		  System.out.println("The top element is " + s.peek());
		  System.out.println("Popping " + s.pop() +
		  " from the top of the stack");
		  System.out.println("Here is the stack:\n" + s + "\n");

		  System.out.println("The top element is " + s.peek());
		  System.out.println("Popping " + s.pop() +
		  " from the top of the stack");
		  System.out.println("Here is the stack:\n" + s + "\n");


		  Queue q = new Queue(), q2; System.out.println("Here is the queue:\n"
		  + q + "\n"); if (q.isEmpty()) {
		  System.out.println("The queue is empty"); } else {
		  System.out.println("The queue is currently not empty"); }

		  System.out.println("Adding items to the queue"); q.enqueue(7);
		  q.enqueue(2); q.enqueue(5); q.enqueue(0); q.enqueue(6);

		  q2 = q.clone();

		  System.out.println(q.front() + " is first in line");
		  System.out.println("Here is the queue:\n" + q + "\n");

		  if (q.isEmpty()) { System.out.println("The queue is empty"); } else {
		  System.out.println("The queue is currently not empty"); }

		  System.out.println(q.dequeue() +
		  " gets served and leaves the queue");
		  System.out.println("Here is the queue:\n" + q + "\n");

		  System.out.println(q.dequeue() +
		  " gets served and leaves the queue");
		  System.out.println("Here is the queue:\n" + q + "\n");

		  System.out.println(q.dequeue() +
		  " gets served and leaves the queue");
		  System.out.println("Here is the queue:\n" + q + "\n");

		  System.out.println(q.dequeue() +
		  " gets served and leaves the queue");
		  System.out.println("Here is the queue:\n" + q + "\n");

		  System.out.println(q.dequeue() +
		  " gets served and leaves the queue");
		  System.out.println("Here is the queue:\n" + q + "\n");

		  System.out.println(q.dequeue() +
		  " gets served and leaves the queue2");
		  System.out.println("Here is the queue:\n" + q + "\n");

		  System.out.println("Here is the queue:\n" + q2 + "\n");


		Deque d = new Deque();
		if (d.isEmpty()) {
			System.out.println("The queue is empty");
		} else {
			System.out.println("The queue is currently not empty");
		}

		System.out.println("Here is the deque:\n" + d + "\n");

		System.out.println("Adding items to the back");
		d.enqueueBack(3);
		d.enqueueBack(7);

		System.out.println("Here is the deque:\n" + d + "\n");

		System.out.println("Adding items to the front");
		d.enqueueFront(6);
		d.enqueueFront(0);

		System.out.println("Here is the deque:\n" + d + "\n");

		if (d.isEmpty()) {
			System.out.println("The queue is empty");
		} else {
			System.out.println("The queue is currently not empty");
		}

		System.out.println("Removing " + d.dequeueFront() + " from the front");
		System.out.println("Here is the deque:\n" + d + "\n");
		System.out.println("Removing " + d.dequeueBack() + " from the back");
		System.out.println("Here is the deque:\n" + d + "\n");

		System.out.println("Removing " + d.dequeueFront() + " from the front");
		System.out.println("Here is the deque:\n" + d + "\n");
		System.out.println("Removing " + d.dequeueBack() + " from the back");
		System.out.println("Here is the deque:\n" + d + "\n");

		System.out.println("Removing " + d.dequeueFront() + " from the front");
		System.out.println("Here is the deque:\n" + d + "\n");
		System.out.println("Removing " + d.dequeueBack() + " from the back");
		System.out.println("Here is the deque:\n" + d + "\n");
	}
}

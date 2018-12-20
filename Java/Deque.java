/*
	Mohamed Ameen Omar
	u16055323
*/

public class Deque
{
	private Queue queue;

	Deque()
	{
		queue = new Queue();
	}

	Deque(Deque other)
	{
		this.queue = new Queue(other.queue);
	}

	public void enqueueFront(int elem)
	{
		if(elem < 0)
		{
			return;
		}

		else
		{
			if(queue == null)
			{
				queue = new Queue();

				queue.enqueue(elem);
			}

			else
			{
				//create a new queue, add to the front


				Queue temp = new Queue();

				temp.enqueue(elem);

				//now we need to remove front of current and add to the back of the new

				int value = queue.dequeue();

				while(value != -1)
				{
					temp.enqueue(value);
					value = queue.dequeue();
				}

				queue = temp;

			}
		}
	}

	/*
	This function adds the element passed
	as a parameter to the back of the queue.
	Any attempt to insert anything invalid
	should be ignored.
	*/
	public void enqueueBack(int elem)
	{
		if(elem < 0)
		{
			return;
		}

		else
		{
			if(queue == null)
			{
				queue = new Queue();
				queue.enqueue(elem);
			}

			else
			{
				queue.enqueue(elem);
			}
		}
	}

	/*
	This function removes and returns the
	element at the front of the queue. If
	there is no such element or the operation
	is invalid, return -1 to serve as an
	error code.
	*/
	public int dequeueFront()
	{

		//check if empty
		if(isEmpty())
		{
			return -1;
		}

		else
		{

			int value = queue.dequeue();

			return value;

		}
	}

	/*
	This function removes and returns the
	element at the back of the queue. If
	there is no such element or the operation
	is invalid, return -1 to serve as an
	error code.
	*/
	public int dequeueBack()
	{
		if(queue.isEmpty())
		{
			return -1;
		}

		else
		{
			//we need to remove from the back
			//so we can deque from front and enque from front to reverse
			//then we can deque like normal to remove first element
			//then reverse again

			Deque temp = new Deque();

			int value = this.dequeueFront();

			while(value != -1)
			{
				temp.enqueueFront(value);
				value = this.dequeueFront();
			}

			//now our first element is what we need to delete

			int toDelete = temp.dequeueFront();

			//now we need to reverse again

			value = temp.dequeueFront();

			while(value != -1)
			{
				this.enqueueFront(value);
				value = temp.dequeueFront();
			}

			return toDelete;

		}

	}

	/*
		This function returns true if the queue is
		empty, and false otherwise.
	*/
	public boolean isEmpty()
	{
		if(queue == null)
		{
			return true;
		}

		return queue.isEmpty();


	}

	public Deque clone()
	{
		Deque temp = new Deque(this);
		return temp;
	}

	public String toString()
	{

		String temp = queue.toString();

		return temp;
	}

}

/*
	Mohamed Ameen Omar
	u16055323
*/

public class Queue
{
	private Stack stack;


	@Override
	public Queue clone()
	{
		Queue temp = new Queue(this);
		return temp;
	}

	@Override
	public String toString()
	{
		String temp = stack.toString();
		return temp;
	}

	Queue()
	{
		stack = new Stack();
	}

	Queue(Queue other)
	{
		stack = new Stack(other.stack);
	}

	/*
	The enqueue function places the element
	passed in as a parameter into the queue.
	Any attempts to insert anything other than
	a positive integer should be ignored.
	*/
	public void enqueue(int elem)
	{

		if(elem < 0)
		{

			return;
		}

		else
		{

			if(stack == null)
			{
				stack = new Stack();

				stack.push(elem);
			}

			else
			{
				Stack tempStack = new Stack();

				int value = stack.pop();

				while(value != -1)
				{

					tempStack.push(value);

					value = stack.pop();
				}

				tempStack.push(elem);

				if(stack != null)
				{

					stack = new Stack();
				}

				value = tempStack.pop();

				while(value != -1)
				{
					stack.push(value);

					value = tempStack.pop();
				}

				if(tempStack != null)
				{
					tempStack = null;
				}

				return;
			}
		}
	}


	/*
	The dequeue function removes and returns the
	appropriate element from the queue.  If for
	whatever reason an attempt is made to perform
	an invalid operation, return -1 to serve as
	an error code.
	*/
	public int dequeue()
	{
		if(isEmpty())
		{
			return -1;
		}

		else
		{
			int value = stack.pop();

			return value;
		}
	}

	/*
	The isEmpty function returns true if the queue
	is empty and false otherwise.
	*/
	public boolean isEmpty()
	{
		if(stack == null)
		{
			return true;
		}

		return stack.isEmpty();
	}

	/*
	This function returns but does not remove the
	element at the front of the queue.  Return -1
	to indicate any errors.
	*/
	public int front()
	{
		if(isEmpty())
		{
			return -1;
		}

		return stack.peek();
	}



}

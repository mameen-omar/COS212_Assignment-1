/*
	Mohamed Ameen Omar
	u16055323
*/

public class Stack
{
	@Override
	public Stack clone()
	{
		Stack temp = new Stack(this);

		return temp;
	}

	@Override
	public String toString()
	{
		String temp = list.toString();

		return temp;
	}

	Stack()
	{
		list = new CircularList();
	}

	Stack(Stack other)
	{
		list = new CircularList(other.list);
	}

	/*
	The push function pushes an element onto the stack.
	Any attempt to push anything other than a positive
	integer should be ignored.
	*/
	public void push(int elem)
	{
		if(elem < 0)
		{
			return;
		}

		else
		{
			if(list == null)
			{
				list = new CircularList();
			}

			list.addToFront(elem);

			return;
		}
	}

	/*
	The pop function removes and returns the element at
	the top of the stack.  If for whatever reason a
	request for the pop function is invalid, return -1
	as an error code.
	*/
	public int pop()
	{

		if(isEmpty())
		{
			return -1;
		}


		//tempList is our original reversed

		CircularList tempList = new CircularList();

		int returnVal = list.deleteFromBack();

		int value = 55;

		while(value != -1)
		{
			value = list.deleteFromBack();

			if(value != -1)
			{
				tempList.addToFront(returnVal);
				returnVal = value;
			}
		}


		list = tempList.clone();

		//now our list is reversed


		return returnVal;


	}

	/*
	The peek function returns the element at
	the top of the stack without removing it.
	If for whatever reason a request for the
	peek function is invalid, return -1 as an
	error code.
	*/
	public int peek()
	{

		if(isEmpty())
		{
			return -1;
		}

		Stack newStack = new Stack();

		newStack = this.clone();

		return newStack.pop();



	}

	/*
	The isEmpty function returns true if the stack
	is empty and false otherwise.
	*/
	public boolean isEmpty()
	{
		if(list == null)
		{
			return true;
		}
		CircularList tempList = new CircularList();
		tempList = list.clone();

		if(tempList.deleteFromBack() == -1)
		{
			return true;
		}

		else
		{
			return false;
		}

	}

	private CircularList list;

}

/*
	Mohamed Ameen Omar
	u16055323
*/

public class CircularList
{
	private Node tail;

	private class Node
	{

		public int data;
		public Node next;

		Node(int elem, Node node)
		{
			data = elem;
			next = node;
		}

		Node(int elem)
		{
			data = elem;
			next = null;
		}
	}

		@Override
		public String toString()
		{
			if(tail == null)
			{
				String output = "[]";

				return output;

			}

			//only one element
			else if(tail.next == tail)
			{
				String output = "[" + tail.data;
				output+= "]";

				return output;
			}

			else
			{
				String output = "[";

				Node temp = tail.next;

				output += temp.data;

				temp = temp.next;

				while(temp != tail)
				{
					output += ",";
					output += temp.data;
					temp = temp.next;
				}

				output += ",";
				output += temp.data;
				output += "]";

				return output;
			}

		}

	@Override
	public CircularList clone()
	{
		return new CircularList(this);
	}

	/*Default constructor*/
	CircularList()
	{
		tail = null ;
	}

	CircularList(CircularList other)
	{
		if(this.tail != null)
		{
			//delete everything in the current list
			while(this.tail != null)
			{
				deleteFromBack();
			}
		}

		//this is empty

		//if empty
		if(other.tail == null)
		{
			return;
		}

		//only one element in other
		if(other.tail == (other.tail).next)
		{
			Node temp = new Node((other.tail).data);


			temp.next = temp;
			this.tail = temp;

			return;
		}

		//more than one

		Node otherPointer = other.tail;

		//other points to head of right list
		otherPointer = otherPointer.next;

		//add the first node
		this.tail = new Node(otherPointer.data);
		//move to next node
		otherPointer = otherPointer.next;
		Node thisHead = tail;
		while(otherPointer != other.tail)
		{
			//add the element
			tail.next = new Node(otherPointer.data);
			otherPointer = otherPointer.next;
			tail = tail.next;
		}
		//add the last element
		tail.next = new Node(otherPointer.data);

		tail = tail.next;
		tail.next = thisHead;

		return;
	}

	public void addToFront(int elem)
	{
		if(elem < 0)
		{
			return;
		}

		//only one node after addtion
		else if(tail == null)
		{
			//create
			tail = new Node(elem);

			//next of temp points to itself
			tail.next = tail;
			//will be the first and last node in the list

		}

		//only one node
		else if(tail.next == tail)
		{
			Node temp = new Node(elem);

			temp.next = tail;
			tail.next = temp;
		}



		else
		{
			//create Node
			Node temp = new Node(elem);

			//temp becomes first
			temp.next = (tail.next);
			//last node must point to the first Node
			tail.next = temp;

		}

	}

	/*
	This function should remove and return the
	element at the back of the list.  If there
	is no such element or it is an ivalid delete
	for whatever reason, then return -1 to serve
	as an "error code".
	*/
	public int deleteFromBack()
	{
		//nothing inside
		if(tail == null)
		{
			return -1;
		}

		//only one element
		else if(tail.next == tail)
		{
			int dataToReturn = tail.data;

			tail = null;

			return dataToReturn;

		}

		else
		{
			Node temp = tail.next;

			Node head = tail.next;
			//temp points to the first node

			//now traverse till the second last node
			while(temp.next != tail)
			{
				temp = temp.next;
			}

			int dataToReturn = tail.data;

			tail = temp;

			temp.next = head;

			return dataToReturn;
		}

	}


}

#include "Deque.h"

/*
Provide all of the implementation for the Deque
class in this file
*/

/*
		The overloaded stream operator for the Deque class.
		If a Deque object is printed and contains the elements 5,4,3 and
		2, in this order with 5 being the front element and 2 the last, the
		output MUST be in the following format: [5,4,3,2]
		There are no white spaces in the string.  You will have to replace this
		operator with an appropriate equivalent in your Java code
		*/
		ostream& operator<<(ostream& os,Deque& c)
		{
			if(c.queue == 0)
			{
				os <<"[]";
				return os;
			}
			os << *(c.queue);

			return os;
		}

		/*
		The overloaded assignment operator.  You will have to replace this
		operator with an appropriate equivalent in your Java code
		*/
		Deque& Deque::operator=(const Deque& other)
		{
			if(this->queue == 0)
			{
				queue = new Queue;
			}
			*(this->queue) = *(other.queue);

			return *this;
		}

		/*
		The default constructor.
		*/
		Deque::Deque()
		{
			queue = new Queue;
		}

		/*
		The destructor.
		*/
		Deque::~Deque()
		{
			if(queue == 0)
			{
				return;
			}

			else
			{
				delete queue;
				queue = 0;
			}
		}

		/*
		This function adds the element passed
		as a parameter to the front of the queue.
		Any attempt to insert anything invalid
		should be ignored.
		*/
		void Deque::enqueueFront(int elem)
		{
			if(elem < 0)
			{
				return;
			}

			else
			{
				if(queue == 0)
				{
					queue = new Queue;

					queue->enqueue(elem);
				}

				else
				{
					//create a new queue, add to the front


					Queue* temp = new Queue;
					temp->enqueue(elem);

					//now we need to remove front of current and add to the back of the new

					int value = queue->dequeue();

					while(value != -1)
					{
						temp->enqueue(value);
						value = queue->dequeue();
					}

					if(queue != 0)
					{
						delete queue;
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
		void Deque::enqueueBack(int elem)
		{
			if(elem < 0)
			{
				return;
			}

			else
			{
				if(queue == 0)
				{
					queue = new Queue;
					queue->enqueue(elem);
				}

				else
				{
					queue->enqueue(elem);
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
		int Deque::dequeueFront()
		{

			//check if empty
			if(isEmpty())
			{
				return -1;
			}

			else
			{

				int value = queue->dequeue();

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
		int Deque::dequeueBack()
		{
			if(queue->isEmpty())
			{
				return -1;
			}

			else
			{
				//we need to remove from the back
				//so we can deque from front and enque from front to reverse
				//then we can deque like normal to remove first element
				//then reverse again

				Deque* temp = new Deque;

				int value = this->dequeueFront();

				while(value != -1)
				{
					temp->enqueueFront(value);
					value = this->dequeueFront();
				}

				//now our first element is what we need to delete

				int toDelete = temp->dequeueFront();

				//now we need to reverse again

				value = temp->dequeueFront();

				while(value != -1)
				{
					this->enqueueFront(value);
					value = temp->dequeueFront();
				}

				if(temp != 0)
				{
					delete temp;
				}

				return toDelete;



			}

		}

		/*
		This function returns true if the queue is
		empty, and false otherwise.
		*/
		bool Deque::isEmpty()
		{
			if(queue == 0)
			{
				return true;
			}

			return queue->isEmpty();

			return false;
		}

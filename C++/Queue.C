#include "Queue.h"

using namespace std;

 /*
Provide all of the implementation for the Queue
class in this file
 */

/*
		The overloaded stream operator for the Queue class.
		If a Queue object is printed and contains the elements 5,4,3 and
		2, in this order with 5 being the front element and 2 the last, the
		output MUST be in the following format: [5,4,3,2]
		There are no white spaces in the string.  You will have to replace this
		operator with an appropriate equivalent in your Java code
		*/
		ostream& operator<<(ostream& os,Queue& c)
		{
			if(c.stack == 0)
			{
				os << "[]";
				return os;
			}
			os << *(c.stack);

			return os;
		}

		/*
		The overloaded assignment operator.  You will have to replace this
		operator with an appropriate equivalent in your Java code
		*/
		Queue& Queue::operator=(const Queue& other)
		{
				if(this->stack == 0)
				{
					this->stack = new Stack;
				}





				*(this->stack) = *(other.stack);

				return *this;
		}


		/*
		The default constructor.
		*/
		Queue::Queue()
		{
			stack = new Stack;
		}

		/*
		The destructor.
		*/
		Queue::~Queue()
		{
			if(stack == 0)
			{
				return;
			}

			else
			{
				delete stack;

				stack = 0;

				return;
			}
		}

		/*
		The enqueue function places the element
		passed in as a parameter into the queue.
		Any attempts to insert anything other than
		a positive integer should be ignored.
		*/
		void Queue::enqueue(int elem)
		{


			if(elem < 0)
			{

				return;
			}

			else
			{

				if(stack == 0)
				{
					stack = new Stack;

					stack->push(elem);
				}

				else
				{
					Stack *tempStack = new Stack();

					int value = stack->pop();

					while(value != -1)
					{

						tempStack->push(value);

						value = stack->pop();


					}

					tempStack->push(elem);

					if(stack != 0)
					{
						delete stack;
						stack = new Stack;
					}

					value = tempStack->pop();

					while(value != -1)
					{
						stack->push(value);

						value = tempStack->pop();
					}

					if(tempStack != 0)
					{
						delete tempStack;

						tempStack = 0;
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
		int Queue::dequeue()
		{
			if(isEmpty())
			{
				return -1;
			}

			else
			{
				int value = stack->pop();

				return value;
			}
		}

		/*
		The isEmpty function returns true if the queue
		is empty and false otherwise.
		*/
		bool Queue::isEmpty()
		{
			if(stack == 0)
			{
				return true;
			}

			return stack->isEmpty();


		}

		/*
		This function returns but does not remove the
		element at the front of the queue.  Return -1
		to indicate any errors.
		*/
		int Queue::front()
		{
			if(isEmpty())
			{
				return -1;
			}
			Stack * tempSTack = new Stack;

			*tempSTack = *stack;

			int value = stack->peek();
			if(stack != 0)
			{
				delete stack;

				stack = new Stack;
			}

			*stack = *tempSTack;

			tempSTack = 0;

			return value;
		}

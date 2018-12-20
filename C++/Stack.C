#include "Stack.h"

 /*
Provide all of the implementation for the Stack
class in this file
 */

/*
		The overloaded stream operator for the Stack class.
		If a Stack object is printed and contains the elements 5,4,3 and
		2, with 5 being the top element and 2 the bottom, the
		output MUST be in the following format: [5,4,3,2]
		There are no white spaces in the string.  You will have to replace this
		operator with an appropriate equivalent in your Java code
		*/
		ostream& operator<<(ostream& os,Stack& c)
		{
			if(c.list == 0)
			{
				os << "[]";
				return os;
			}
			os << *(c.list);

			return os;
		}

		/*
		The overloaded assignment operator.  You will have to replace this
		operator with an appropriate equivalent in your Java code
		*/
		Stack& Stack::operator=(const Stack& other)
		{
			if(list == 0)
			{
				list = new CircularList;
			}

			else if(other.list == 0)
			{
				delete list;
				list = new CircularList;
			}
			*(this->list) = *(other.list);


			return *this;

		}

		/*
		The default construcor.
		*/
		Stack::Stack()
		{
			list = new CircularList;
		}

		/*
		The destructor.
		*/
		Stack::~Stack()
		{
			if(list == 0)
			{
				return;
			}

			else
			{
				delete list;

				list= 0;
			}
		}

		/*
		The push function pushes an element onto the stack.
		Any attempt to push anything other than a positive
		integer should be ignored.
		*/
		void Stack::push(int elem)
		{
			if(elem < 0)
			{
				return;
			}

			else
			{
				if(list == 0)
				{
					list = new CircularList;
				}
				list->addToFront(elem);

				return;
			}
		}

		/*
		The pop function removes and returns the element at
		the top of the stack.  If for whatever reason a
		request for the pop function is invalid, return -1
		as an error code.
		*/
		int Stack::pop()
		{

					if(isEmpty())
					{
						return -1;
					}


					//tempList is our original reversed
					CircularList* tempList = new CircularList;

					//we are deleting our list and making tempList a reversed version of our original so we can use
					//delete from Back

					int returnVal = list->deleteFromBack();

					int value = 55;

					while(value != -1)
					{
						value = list->deleteFromBack();

						if(value != -1)
						{
							tempList->addToFront(returnVal);
							returnVal = value;

						}
					}


					*list = *tempList;

					//now our list is reversed
					if(tempList != 0)
					{
						delete tempList;
						tempList = 0;
					}

					return returnVal;


		}

		/*
		The peek function returns the element at
		the top of the stack without removing it.
		If for whatever reason a request for the
		peek function is invalid, return -1 as an
		error code.
		*/
		int Stack::peek()
		{

			if(isEmpty())
			{
				return -1;
			}

			Stack *newStack = new Stack();
			newStack = this;
			return newStack->pop();



		}

		/*
		The isEmpty function returns true if the stack
		is empty and false otherwise.
		*/
		bool Stack::isEmpty()
		{
			if(list == 0)
			{
				return true;
			}
			CircularList *tempList = new CircularList();
			*tempList = *list;

			return tempList->deleteFromBack() == -1;

		}

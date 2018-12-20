#include "CircularList.h"

/*
Provide all of the implementation for the CircularList
class in this file
*/

/*
		The overloaded stream operator for the CircularList class.
		If a CircularList object is printed and contains the elements 5,4,3 and
		2, in this order with 5 being the first element and 2 the last, the
		output MUST be in the following format: [5,4,3,2]
		There are no white spaces in the string.  You will have to replace this
		operator with an appropriate equivalent in your Java code
		*/
		ostream& operator<<(ostream& os,CircularList& c)
		{
			if(c.tail == 0)
			{
				os << "[]";
				return os;
			}
			//only one element
			else if((c.tail)->next == c.tail)
			{
				os << "[" << (c.tail)->data << "]";
				return os;
			}


			CircularList::Node *temp = c.tail;
			temp = temp->next;

			os<<"[" << temp->data <<",";

			temp = temp->next;
			//until the second last node
			while(temp != c.tail)
			{
				os << temp->data << ",";

				temp = temp->next;
			}

			//temp is the tail so we are at the last node

			os<< temp->data << "]";

			return os;
		}

		/*
		The overloaded assignment operator.  You will have to replace this
		operator with an appropriate equivalent in your Java code
		*/
		CircularList& CircularList::operator=(const CircularList& other)
		{


			if(this->tail != 0)
			{
				//delete everything in the current list
				while(this->tail != 0)
				{
					deleteFromBack();
				}
			}


			//this is empty

			//if empty
			if(other.tail == 0)
			{
				return *this;
			}

			//only one element in other
			if(other.tail == (other.tail)->next)
			{
				Node * temp = new Node(other.tail->data);


				temp->next = temp;
				tail = temp;

				return (*this);
			}

			//more than one

			Node *otherPointer = other.tail;

			//other points to head of right list
			otherPointer = otherPointer->next;

			//add the first node
			tail = new Node(otherPointer->data);
			//move to next node
			otherPointer = otherPointer->next;
			Node *thisHead = tail;
			while(otherPointer != other.tail)
			{
				//add the element
				tail->next = new Node(otherPointer->data);
				otherPointer = otherPointer->next;
				tail = tail->next;
			}
			//add the last element
			tail->next = new Node(otherPointer->data);

			tail = tail->next;
			tail->next = thisHead;

			return *this;
		}

		/*Default constructor*/
		CircularList::CircularList()
		{
			tail = 0 ;
		}

		/*Destructor*/
		CircularList::~CircularList()
		{
			Node * temp = this->tail;
			//if empty
			if(tail == 0)
			{
				return;
			}

			else if(tail == tail->next)
			{
				delete tail;
				tail = 0;
				temp = 0;

				return;
			}

			else
			{
				//temp is the first Node
				temp = temp->next;
				//delete all until we are at the last node
				while(temp != tail)
				{
					Node * tempNext = temp->next;

					delete temp;

					temp = tempNext;
					tempNext = 0;
				}

				//now delete last node
				delete temp;
				temp = 0;
				tail = 0;

			}
		}//end of destructor

		/*
		The function should add the element passed
		in as a parameter to the front of the list.
		Any attempts to insert anything other than
		a positive integer into the list should be
		ignored.
		*/
		void CircularList::addToFront(int elem)
		{
			if(elem < 0)
			{
				return;
			}

			//only one node after addtion
			else if(tail == 0)
			{
				//create
				tail = new Node(elem);

				//next of temp points to itself
				tail->next = tail;
				//will be the first and last node in the list

			}

			//only one node
			else if(tail->next == tail)
			{
				Node * temp = new Node(elem);

				temp->next = tail;
				tail->next = temp;
			}



			else
			{
				//create Node
				Node * temp = new Node(elem);

				//temp becomes first
				temp->next = (tail->next);
				//last node must point to the first Node
				tail->next = temp;

			}

		}

		/*
		This function should remove and return the
		element at the back of the list.  If there
		is no such element or it is an ivalid delete
		for whatever reason, then return -1 to serve
		as an "error code".
		*/
		int CircularList::deleteFromBack()
		{
			//nothing inside
			if(tail == 0)
			{
				return -1;
			}

			//only one element
			else if(tail->next == tail)
			{
				int dataToReturn = tail->data;

				delete tail;

				tail = 0;

				return dataToReturn;

			}

			else
			{
				Node * temp = tail->next;

				Node * head = tail->next;
				//temp points to the first node

				//now traverse till the second last node
				while(temp->next != tail)
				{
					temp = temp->next;
				}

				int dataToReturn = tail->data;

				delete tail;

				tail = temp;

				temp->next = head;

				return dataToReturn;


			}
		}

#include "SLList.h"

//***************************************************************************
//                       Class SLList Method::SLList
//							   Paramaters: None 
//                              Returns: None
//                            Complexity: O(1)
//
//	This is the default constructor for the clast. It creates the Header Node
//	the Tail Node, the pointer to the Header Node, and the Last Node Pointer
//	which points to the Header node in an empty list. It also sets the size
//	of the list to 0. The complexity is O(1) since this constructor will 
//	take the same amount of time whenever it is called.
//
//***************************************************************************

SLList::SLList() {


	_LastNodePtr = new Node(0, nullptr);
	_HeaderPtr = new Node(0, _LastNodePtr);
	_LastNodePtr = _HeaderPtr;

	_size = 0;
}

//***************************************************************************
//							Class SLList Method::SLList
//						   Paramaters: const SLList& copy
//							     Returns: None
//							    Complexity: O(n)
//
//	This is a copy constructor for the class that does a deep copy since 
//	there is dynamic memory. It creates a new list and if the original
//	list is not empty it populates the new list with the new nodes containing
//	the same values from the original list by using the push_back method.
//	The complexity is n since it will create n nodes in the copy.
//
//***************************************************************************

SLList::SLList(const SLList& copy)
{
	_LastNodePtr = new Node(0, nullptr);
	_HeaderPtr = new Node(0, _LastNodePtr);
	_LastNodePtr = _HeaderPtr;


	if (copy._size != 0)
	{
		Node *tmp = copy._HeaderPtr->next;


		for (int i = 0; i< copy._size; ++i)
		{
			push_back(tmp->value);
			tmp = tmp->next;
		}
	}

}

//***************************************************************************
//						 Class SLList Method::~SLList
//							  Paramaters: None
//                              Returns: None
//                            Complexity: O(n)
//
//	This is the class destructor that removes the dynamically allocated 
//	memory. The complexity is O(n) since the size of the list determines
//	how many operations will need to be done to release the memory.
//
//***************************************************************************

SLList::~SLList() {

	Node *tmp = _HeaderPtr->next;
	Node *tmp2 = _HeaderPtr->next->next;

	for (int i = 0; i<_size; ++i)
	{
		delete[] tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
	}


}

//***************************************************************************
//						 Class SLList Method::push_back
//							  Paramaters: int i
//                              Returns: None
//                            Complexity: O(1)
//
//	This method creates one new node with the value passed to it and increases
//	the size variable of the class that tracks the number of nodes created.
//	The complexity is O(1) since it is a set number of operations whenever it
//	is called.
//
//***************************************************************************


void SLList::push_back(int i) {

	_LastNodePtr = _LastNodePtr->next = new Node(i, _LastNodePtr->next);
	_size++;

}

//***************************************************************************
//						 Class SLList Method::print
//							  Paramaters: int i
//                              Returns: None
//                            Complexity: O(n)
//
//	This method prints the first i items or if 0, all of them. If the list
//	has 0 elements it prints empty. The complexity is O(n) since worst case
//	execution will be to print the values of n nodes.
//
//***************************************************************************

void SLList::print(int i) {


	Node *tmp = _HeaderPtr->next;

	if ((i == 0) | (i > _size) | (i < 0))
		i = _size;

	if (empty())
		std::cout << "empty";
	else
	{

		for (int j = 0; j< i; ++j)
		{
			std::cout << tmp->value;
			if (j < i - 1)
				std::cout << ",";

			tmp = tmp->next;
		}
	}

	std::cout << std::endl;
}

//***************************************************************************
//						 Class SLList Method::push_front
//							  Paramaters: int i
//                              Returns: None
//                            Complexity: O(1)
//
//	This method inserts a new node on the front of the list and increments
//	the size variable that tracks the numebr of nodes. It is O(1) since there
//	are a set number of operations whenever it is called.
//
//***************************************************************************

void SLList::push_front(int i)
{
	_HeaderPtr->next = new Node(i, _HeaderPtr->next);
	_size++;
}

//***************************************************************************
//						 Class SLList Method::pop_front
//							  Paramaters: None
//                              Returns: None
//                            Complexity: O(1)
//
//	This method removes the front node of the list and decrements the size
//	counter. It is O(1) since there are a set number of operation whenever
//	it is called.
//
//***************************************************************************

void SLList::pop_front()
{
	if (empty())
		std::cout << "Error: List is empty!" << std::endl;
	else
	{
		Node *tmp = _HeaderPtr->next;
		_HeaderPtr->next = _HeaderPtr->next->next;
		delete[] tmp;
		_size = _size - 1;

		if (_size == 0)
			_LastNodePtr = _HeaderPtr;
	}
}

//***************************************************************************
//						 Class SLList Method::front
//							  Paramaters: None
//                              Returns: int
//                            Complexity: O(1)
//
//	This method returns the value of the first node of the linked list or 
//	prints error if the list is empty. This is O(1) since it is a set number
//	of operations whenver it is called.
//
//***************************************************************************

int SLList::front()
{
	if (empty())
	{
		std::cout << "empty" << std::endl;
		return -1;
	}


	return _HeaderPtr->next->value;
}

//***************************************************************************
//						 Class SLList Method::empty
//							  Paramaters: None
//                              Returns: Boolean
//                            Complexity: O(1)
//
//	This method returns true if the list is empty or false if the list is 
//	not empty. This is O(1) since it is a set number of operations whenever
//	it is called.
//
//***************************************************************************

bool SLList::empty()
{
	if (_size == 0)
		return true;
	else
		return false;
}

//***************************************************************************
//						 Class SLList Method::size
//							  Paramaters: None
//                              Returns: int
//                            Complexity: O(1)
//
//	This method returns the size of the list. This is O(1) since it is a set 
//	number of operations whenever it is called.
//
//***************************************************************************

int SLList::size()
{
	return _size;

}

//***************************************************************************
//						 Class SLList Method::operator=
//							  Paramaters: const SLList &rhs
//                              Returns: Pointer
//                            Complexity: O(n)
//
//	This is an overloaded operator that makes a copy of one list to another
//	if this list has elements by using the copy constructor. This method
//	was provided by the instructor but modified due to errors wit swap.
//
//***************************************************************************

SLList & SLList::operator=(const SLList & rhs) 
{
	if (&rhs != this) 
	{
		SLList N(rhs);
		return N;
	}
	else 
		return *this;
}

//***************************************************************************
//						 Class SLList Friend Function::operator <<
//							  Paramaters: ostream&, const SLList&
//                              Returns: ostream&
//                            Complexity: O(n)
//
//	This is an overloaded operator function that prints out the list partially
//	It prints out the size and then the first 10 values of the list. If more
//	than 10 values it prints a ... and then the final value. If less than 10
//	values it prints all values. If empty it prints empty. This is worst case
//	complexity of O(1) since it returns a set number of values regardless
//	of the size of the list.
//
//***************************************************************************

std::ostream& operator << (std::ostream& output, const SLList& list)
{

	output << "List size = " << list._size;

	if (list._size == 0)
		return output << std::endl;

	output << ":";

	 SLList::Node* tmp = list._HeaderPtr->next;



	if (list._size > 10)
	{
		for (int i = 0; i < 10; ++i)
		{
			output << tmp->value << ",";
			tmp = tmp->next;
		}

		return output << "..." << list._LastNodePtr->value << std::endl;
	}

	else
	{
		for (int i = 0; i < list._size; ++i)
		{
			output << tmp->value;
			if (i < list._size - 1)
				output << ",";
			tmp = tmp->next;
		}
		return output << std::endl;
	}
}


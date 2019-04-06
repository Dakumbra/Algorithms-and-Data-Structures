#include <ostream>
#include <iostream>




class SLList
{

	struct Node
	{
		int value;
		Node *next;
		Node(int v, Node *n) : value(v), next(n) {};
	};

public:

	Node *_HeaderPtr;       // Pointer to Header Node
	Node *_LastNodePtr;     // Pointer to Node before Trailer Node
	int _size;              // Number of values in list

	SLList();
	SLList(const SLList& copy);
	~SLList();

	void push_back(int i);
	void print(int i);
	void push_front(int i);
	void pop_front();
	int front();
	bool empty();
	int size();

	SLList & SLList::operator=(const SLList & rhs);

	friend std::ostream& operator << (std::ostream& output, const SLList& list);
};

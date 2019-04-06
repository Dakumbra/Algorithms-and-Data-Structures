//***************************************************************************
//                                  Project #1
//                              Name:  Samuel Weems
//                           Course:  CMPS 3013, Fall 17
//                         Professor: Dr. Richard P. Simpson
//                              Date: September 27 2017
//***************************************************************************
//                                  Introduction
//
//	This project is a Linked List class, called SLList whose nodes contain
//	an integer and a next ptr. The class is a singly linked list that contains
//	a header node, a trailer node, a pointer to the header, and a pointer to
//	the last node before the trailer. There is a variable _size which contains
//	the number of values in the list.
//
//***************************************************************************
//                              Program Complexity
//									  O(n)
//
//	The complexity of this program is O(n) since the worst case methods are
//	O(n). A discussion of those methods is with those methods.
//
//***************************************************************************
//
//  I have written the entire program as turned in and have not copied this
//  code, or parts of this code from the internet or another student.
//
//                                  Signature _______________________________
//
//***************************************************************************
#include "SLList.h"


using namespace std;

// Modified 9/22/2017 @ 10:37
int main()
{
	SLList Alst;
	Alst.pop_front();// Should print an error and return
	cout << "Alst="; Alst.print(0);
	for (int i = 0; i < 5; i++) {
		Alst.push_back(i);
	}
	for (int i = 0; i < 5; i++) {
		cout << Alst.front() << endl;
		Alst.pop_front();
	}
	for (int i = 10; i < 15; i++) {
		Alst.push_back(i);
	}
	SLList Blst(Alst);//calls the copy constructor
	cout << "Alst="; Alst.print(0);
	cout << "Blst(3)=";
	Blst.print(3);
	int sum = 0;
	int size = Blst.size();
	cout << "Size of Blst is " << size << endl;
	while (!Blst.empty()) {
		sum += Blst.front();
		Blst.pop_front();
	}
	cout << "Emptied Blst to obtain sum=" << sum << endl;
	SLList Clst(Alst), Dlst;// checks copy constructor and default constructor.
	Dlst.print(0);
	for (int i = 1; i < 20; i++) {
		Dlst.push_back(i * 2);
	}
	cout << Dlst << endl;
	Dlst.push_front(100);
	cout << Clst << endl;

	Alst = Dlst;// Assign D to A
	cout << Alst << endl;
	cout << "Done" << endl;
}

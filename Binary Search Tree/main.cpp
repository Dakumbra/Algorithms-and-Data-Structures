//***************************************************************************
//                                  Project #3
//                              Name:  Samuel Weems
//                           Course:  CMPS 3013, Fall 17
//                         Professor: Dr. Richard P. Simpson
//                              Date: October 25 2017
//***************************************************************************
//                                  Introduction
//
//	This project is a BST research tree. The program is designed to test the
//  effectiveness of asymmetric or symmetric deltetes in a binary search tree.
//  In asymmetric method the program uses a single type of deleteion, either by
//  consistently deleting the predecessor or consistently deleting the
//  successor. The symmetric method is tested by alternating between
//  predecessor and successor deletes. There is a random insertion done after
//  each delete to keep the number of nodes the same. After 100,000 delete/insert
//  pairs the internal path length (IPL) averages are printed and then graphed
//  to give data on the effect of these different methods on the balance of the
//  tree. As described in the attached report, a symmetric method yields a more
//  balanced tree after deletes and insertions.
//
//  In addition to a regular BST structure this program includes private
//  variables that keep track of the size of the tree and a vector that
//  keeps a list of all values in the tree. The vector is helpful in
//  finding a random node value to delete.
//
//***************************************************************************
//
//  I have written the entire program as turned in and have not copied this
//  code, or parts of this code from the internet or another student.
//
//                                  Signature _______________________________
//
//***************************************************************************


#include "BST.h"



using namespace std;

int main() {

	int iterations = 200;
	int treesize = 128;
	int insdelpairs = 100000;

// Asymmetric Deletes, 128 Node Tree, 200 iterations, 100,000 insert/delete


	cout << "Data 128 Node Tree, Asymmetric" << endl;

	vector<long long>iplData(40, 0);// 40 sample ipl values

	cout << "--------------------------------------------------" << endl;

	for (int ct = 0; ct < iterations; ct++) 
	{
		if (ct % 2 == 0)cout << ".";
		BST t(treesize);
		for (int i = 0; i < insdelpairs; i++)
		{
			if (i % 2500 == 0)
				iplData[i / 2500] += t.IPL();
			t.RandDelInsPair(1);
		}
	
	}

	cout << endl;
	for (int i = 0; i < 40; i++)
		cout << iplData[i] / iterations << endl;


// Symmetric Deletes, 128 Node Tree, 200 iterations, 100,000 insert/delete


	cout << "Data 128 Node Tree, Symmetric " << endl;

	fill(iplData.begin(), iplData.end(), 0);

	int symmetricCounter = 1;

	cout << "--------------------------------------------------" << endl;

	for (int ct = 0; ct < iterations; ct++)
	{
		if (ct % 2 == 0)cout << ".";
		BST t(treesize);
		for (int i = 0; i < insdelpairs; i++)
		{
			if (i % 2500 == 0)
				iplData[i / 2500] += t.IPL();

			if (symmetricCounter % 2 == 0)
				 t.RandDelInsPair(1);
			else
				 t.RandDelInsPair(0);

			symmetricCounter = symmetricCounter+1;
		}
	}

	cout << endl;
	for (int i = 0; i < 40; i++)
		cout << iplData[i] / iterations << endl;

	//Treesize changed to 256

	treesize = 256;

	// Asymmetric Deletes, 256 Node Tree, 200 iterations, 100,000 insert/delete


	cout << "Data 256 Node Tree, Asymmetric" << endl;

	fill(iplData.begin(), iplData.end(), 0);

	cout << "--------------------------------------------------" << endl;

	for (int ct = 0; ct < iterations; ct++)
	{
		if (ct % 2 == 0)cout << ".";
		BST t(treesize);
		for (int i = 0; i < insdelpairs; i++)
		{
			if (i % 2500 == 0)
				iplData[i / 2500] += t.IPL();
			t.RandDelInsPair(1);
		}

	}

	cout << endl;
	for (int i = 0; i < 40; i++)
		cout << iplData[i] / iterations << endl;

	// Symmetric Deletes, 256 Node Tree, 200 iterations, 100,000 insert/delete


	cout << "Data 256 Node Tree, Symmetric " << endl;

	fill(iplData.begin(), iplData.end(), 0);

	symmetricCounter = 1;

	cout << "--------------------------------------------------" << endl;

	for (int ct = 0; ct < iterations; ct++)
	{
		if (ct % 2 == 0)cout << ".";
		BST t(treesize);
		for (int i = 0; i < insdelpairs; i++)
		{
			if (i % 2500 == 0)
				iplData[i / 2500] += t.IPL();

			if (symmetricCounter % 2 == 0)
				t.RandDelInsPair(1);
			else
				t.RandDelInsPair(0);

			symmetricCounter = symmetricCounter + 1;
		}
	}

	cout << endl;
	for (int i = 0; i < 40; i++)
		cout << iplData[i] / iterations << endl;


	system("pause");
	return 0;
}


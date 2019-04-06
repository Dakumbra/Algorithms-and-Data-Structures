#include "BST.h"

// Private Methods
// Auxilarry methods (AUX) are written to abide by object oriented program design principles
// so that public functions do not require the passing of the private variable _root of the tree.
// ********************************************************************************************



// Inserts a node into the tree


void BST::insertAux(pTreeNode & tree, const int &item) //1
{
	if (tree == nullptr)
		tree = new treeNode(item);
	else
	{
		if (item < tree->_key)
			insertAux(tree->_left, item);
		else
			insertAux(tree->_right, item);
	}
}


// Prints the tree in numerical order
// Note: move the cout command up 2 lines for a pre-order print, or down two lines for post-order

void BST::inOrderAux(pTreeNode tree) // 2
{
	if (tree != nullptr)
	{
		inOrderAux(tree->_left);
		cout << tree->_key << endl;
		inOrderAux(tree->_right);
	}
}


// This function deletes a node by value replacing with successor

void BST::SdeleteAux(pTreeNode &root, int x)//3
{
	if (root != nullptr)
	{
		pTreeNode tempPtr = nullptr;
		pTreeNode predPtr = nullptr;

		if (x < root->_key)
			SdeleteAux(root->_left, x);
		if (x > root->_key)
			SdeleteAux(root->_right, x);
		if (x == root->_key)
		{
			if (root->_left == nullptr && root->_right == nullptr)
			{
				delete(root);
				root = nullptr;
				return;
			}

			else if (root->_left == nullptr) 
			{
				tempPtr = root->_right;
				delete root;
				root = tempPtr;
			}

			else if (root->_right == nullptr) 
			{
				tempPtr = root->_left;
				delete(root);
				root = tempPtr;
			}

			else 
			{
				tempPtr = root->_right;
				while (tempPtr->_left != nullptr)
				{
					predPtr = tempPtr;
					tempPtr = tempPtr->_left;
				}

				root->_key = tempPtr->_key;

				if (root->_right == tempPtr)
					root->_right = tempPtr->_right;
				else
					predPtr->_left = tempPtr->_right;

				delete tempPtr;
			}
		}
	}
}

// This function deletes a node by value replacing with predecessor

void BST::PdeleteAux(pTreeNode &root, int x) //5
{

	if (root != nullptr)
	{
		pTreeNode tempPtr = nullptr;
		pTreeNode predPtr = nullptr;

		if (x < root->_key)
			PdeleteAux(root->_left, x);
		if (x > root->_key)
			PdeleteAux(root->_right, x);
		if (x == root->_key)
		{
			if (root->_left == nullptr && root->_right == nullptr)
			{
				delete(root);
				root = nullptr;
				return;
			}

			if (root->_left == nullptr)
			{
				tempPtr = root->_right;
				delete root;
				root = tempPtr;
			}

			else if (root->_right == nullptr)
			{
				tempPtr = root->_left;
				delete(root);
				root = tempPtr;
			}

			else
			{
				tempPtr = root->_left;
				while (tempPtr->_right != nullptr)
				{
					predPtr = tempPtr;
					tempPtr = tempPtr->_right;
				}

				root->_key = tempPtr->_key;

				if (root->_left == tempPtr)
					root->_left = tempPtr->_left;
				else
					predPtr->_right = tempPtr->_left;

				delete tempPtr;

			}
		}
	}
}


// This function calculates the current internal path length or IPL of the tree
// The IPL is a measure of the balance of the tree.

int  BST::iplAux(pTreeNode & root, int value) // 7
{
	if (root == nullptr)
		return 0;

	return value + iplAux(root->_right, value + 1) + iplAux(root->_left, value + 1);

}


// Function used to free allocated memory and called by destructor


void BST::DestroyTree(pTreeNode &tree)
{
	if (tree != nullptr)
	{
		DestroyTree(tree->_left);
		DestroyTree(tree->_right);
		delete tree;
		tree = nullptr;
	}
}

// Public Methods
// ********************************************************************************************

// Default constructor


BST::BST()
{
	_root = nullptr;
	_size = 0;
}

// Constructor that creates a tree with random nodes of size passed as parameter

BST::BST(int numValues) //1
{
	_root = nullptr;
	_size = numValues;


	srand((int)time(0));

	for (int i = 0; i<numValues; i++)
	{
		int newValue = (rand() % 32000);
		Insert(newValue);
		valueList.push_back(newValue);
	}
}


// Destructor that calls DestroyTree() private method

BST::~BST() // 4
{
	DestroyTree(_root);
}

// Public insert method

void BST::Insert(int value) //1, Inserts new node,adds it to the vector and increments _size
{
	insertAux(_root, value);
}

// Public print in order method


void BST::Inorder() //2
{
	inOrderAux(_root);
}


// Public Successor delete method

void BST::Sdelete(int value) //3, successor delete from tree, does not modify size or vector
{
	SdeleteAux(_root, value);
}

// Public Predecessor delete Method

void BST::Pdelete(int value) //5, predecessor delete from tree, does not modify size or vector
{
	PdeleteAux(_root, value);
}

// Primary method called in main program that calls either predecessor or successor
// delete based on code (dType) passd to it and then inserts a new random value into
// tree and vector. 


void BST::RandDelInsPair(int dType)
{
	unsigned long size = valueList.size();

	int oldValueLocation = (rand() % size);
	int newValue = (rand() % 32000);


	if (dType == 0)
		Sdelete(valueList[oldValueLocation]);
	else
		Pdelete(valueList[oldValueLocation]);

	valueList[oldValueLocation] = newValue;
	Insert(newValue);
}


// Public internal path length function

int BST::IPL()
{
	return iplAux(_root, 0);
}








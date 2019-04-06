// See BST.cpp for description of methods.

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>


using namespace std;

class BST
{
	struct treeNode;
	typedef treeNode* pTreeNode;

	vector<int> valueList;// holds the values presently in the tree. Normally not in a tree
	int _size;//number of values in tree and in vector;

	struct treeNode {
		int _key;
		pTreeNode _left;
		pTreeNode _right;
		treeNode(int key) : _key(key), _left(nullptr), _right(nullptr) {}
	};

	pTreeNode _root;


	void insertAux(pTreeNode &, const int &item);//1

	void inOrderAux(pTreeNode tree);//2

	void SdeleteAux(pTreeNode & root, int x);//3

	void PdeleteAux(pTreeNode & root, int x);//5

	int  iplAux(pTreeNode & root, int value); // 7

	void DestroyTree(pTreeNode &tree);//4


public:

	BST();  //default constructor

	BST(int numValues);//1, constructs tree with random nodes. It calls insert() multiple times

	~BST();// 4 ,Calls DestroyTree()

	void Insert(int value);//1, Inserts new node,adds it to the vector and increments _size

	void Inorder();

	void Sdelete(int value);//3, successor delete from tree, does not modify size or vector

	void Pdelete(int value); //5, predecessor delete from tree, does not modify size or vector


							 // The following performs an deletion/insertion pair randomly
							 // Randomly selects value in vector , deletes it from tree and
							 // inserts a new random value into vector and tree. Uses either Sdelete(1) or Pdelete(0)

	void RandDelInsPair(int dType);//6

	int IPL(); //7, Calls iplAux() to return the internal path length. Will discuss in class





};

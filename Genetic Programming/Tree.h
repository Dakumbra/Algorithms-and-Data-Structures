#include "Node.h"


class Tree
{
	
    Node* root;

    void buildTreeAux(Node* node);
    void printTreeAux(Node* tree);

public:

	Tree();  //default constructor
    void buildTree();
    void printTree();
  
};

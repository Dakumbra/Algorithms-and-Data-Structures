

#include <iostream>
using namespace std;

class Node
{
    Node* leftLeaf; // Pointer to left child
    Node* rightLeaf; // Pointer to right child
    string type;  // Type of node - Operator, Variable, or Value
    string operation;    // Operation Type - Add, Sub, Multply, or Divide (operatorNode)
    string variable; // Variable (variableNode)
    int value;  // Numerical value (valueNode)
    
public:

	Node();  //default constructor
    void printNode(); // print node values
    string getType(); // Returns type of node
    string getOperation(); // Returns operation
    string getVariable(); // Returns Variable
    int getValue(); // Returns Value
    Node* getLeftLeaf();
    Node* getRightLeaf();
    void setLeftLeaf(Node* node);
    void setRightLeaf(Node* node);

};




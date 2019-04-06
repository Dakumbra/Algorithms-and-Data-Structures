#include "Node.h"
#include "time.h"


// Default constructor which creates a random Node type with random value


Node::Node()
{
    
    leftLeaf = rightLeaf = nullptr;
    value = -1; // default value
    operation = "Null"; //default value
    variable = "Null"; //default value
    
    int typeSelector = rand()%3;
    switch (typeSelector){
        case 0: {
            type = "Operator";
            int operatorSelector = rand()%4;
            switch (operatorSelector){
                case 0:
                    operation = "+";
                    break;
                case 1:
                    operation = "-";
                     break;
                case 2:
                    operation = "*";
                     break;
                case 3:
                    operation = "/";
                     break;
            }
            break;}
        case 1:{
            type = "Variable";
            int variableSelector = rand()%3;
            switch (variableSelector){
                case 0:
                    variable = "x";
                    break;
                case 1:
                    variable = "y";
                    break;
                case 2:
                    variable = "z";
                    break;
            }
            break;}
        case 2:{
            type = "Value";
            value = rand()%11; // Random value 0-10
            break;}
            
    }
    
}

// Print Node contents depending on type

void Node::printNode()
{
    if (type == "Operator"){
        cout << operation << " ";
    }
    
    else if (type == "Variable"){
        cout << variable << " ";
    }
    
    else {
        cout << value << " ";
    }
    
}

// Accessor and Set Functions

string Node::getType(){
    return type;
}

string Node::getOperation(){
    return operation;
}
string Node::getVariable(){
    return variable;
}
int Node::getValue(){
    return value;
}

void Node::setLeftLeaf(Node* node){
    leftLeaf = node;
}
void Node::setRightLeaf(Node* node){
    rightLeaf = node;
}

Node* Node::getLeftLeaf(){
    return leftLeaf;
}
Node* Node::getRightLeaf(){
    return rightLeaf;
}

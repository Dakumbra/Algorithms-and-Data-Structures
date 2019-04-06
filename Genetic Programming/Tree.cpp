#include "Tree.h"




Tree::Tree(){
    root = new Node;
}

void Tree::buildTreeAux(Node* node){
    if (node->getType() == "Operator"){
        Node* newRightLeaf = new Node;
        Node* newLeftLeaf = new Node;
        
        node->setLeftLeaf(newLeftLeaf);
        node->setRightLeaf(newRightLeaf);
        
        buildTreeAux(node->getLeftLeaf());
        buildTreeAux(node->getRightLeaf());
    }
}

void Tree::printTreeAux(Node* tree){
    if (tree != nullptr)
    {
        tree->printNode();
        printTreeAux(tree->getLeftLeaf());
        printTreeAux(tree->getRightLeaf());
    }
}

void Tree::buildTree(){
    buildTreeAux(root);
}

void Tree::printTree(){
    printTreeAux(root);
}




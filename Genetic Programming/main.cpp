//***************************************************************************
//                          Project #5 - Genetic Programming
//                              Name:  Samuel Weems
//                           Course:  CMPS 5463, Fall 2018
//                         Professor: Dr. Richard P. Simpson
//                              Date: November 12 2018
//***************************************************************************
//                                  Introduction
//
//  This program is a simplified version of a section of the concept of
//  genetic programming demonstrated by Larry Gritz. In this program
//  S-expressions are formed using parse trees. This is a simplified version
//  using random binary operators which contains only the Operations (+,-,*,/)
//  the Variables (X,Y,Z) and one random integer (0-10). The program creates
//  100 random parse trees and outputs them in prefix order.
//
//***************************************************************************
//                              Program Complexity
//                                    O(n)
//
//  The program's overall complexity is based on the most complex section
//  of code which is the creation of the nodes and the printing of the values.
//  In both those cases the code is simply order n where n is the number of
//  nodes.
//
//***************************************************************************
//
//  I have written the entire program as turned in and have not copied this
//  code, or parts of this code from the internet or another student.
//
//                                  Signature _______________________________
//
//***************************************************************************


#include "Tree.h"

int main() {
  
    srand(time(NULL));  // Seed Random Number Generator with time
    
    for (int i=0 ; i<100; ++i){
        Tree testTree;
        testTree.buildTree();
        testTree.printTree();
        cout << endl;
    }
   
}

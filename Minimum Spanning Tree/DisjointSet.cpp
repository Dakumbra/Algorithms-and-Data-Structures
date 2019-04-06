
#include "DisjointSet.h"

//***************************************************************************
//					  Class DisjointSet Method: DisjointSet()
//                          Parameters: None
//							 Returns: None
//						    Complexity: O(n)
//
// Class constructor that creates a parent array of size max_nodes.
//***************************************************************************

DisjointSet::DisjointSet()
{
    for (int i=0; i<max_nodes; ++i)
        parentArray.push_back(i);
}

//***************************************************************************
//					  Class DisjointSet Method: PrintParentArray()
//                          Parameters: None
//							 Returns: None
//						    Complexity: O(n)
//
// Simple ouput method that displays entire parent array contents.
//***************************************************************************

void DisjointSet::PrintParentArray()
{

    for (int i=0; i<max_nodes; ++i)
        cout << i << ": " << parentArray[i] << endl;
    
    cout << endl;
}

//***************************************************************************
//					  Class DisjointSet Method: ProjectPrint
//                          Parameters: None
//							 Returns: None
//						    Complexity: O(n log n)
//
// Calculates and prints each Minimal Spanning Tree from smallest to largest
// including total number of nodes in each tree. The sort function has the
// largest complexity making this method O(n log n).
//***************************************************************************


void DisjointSet::ProjectPrint()
{
    vector<int> treeData;
    int treeDataLocation = 0;
    
    vector<int> tempArray = parentArray;
    sort(tempArray.begin(), tempArray.end());
    
    treeData.push_back(1);
    
    for (int i =1; i<parentArray.size(); ++i)
    {
        if (tempArray[i] == tempArray[i-1])
           ++treeData[treeDataLocation];
        else
        {
            ++treeDataLocation;
            treeData.push_back(1);
        }
    }
    
   sort(treeData.rbegin(), treeData.rend());
    
    for (int i=0; i<treeData.size(); ++i)
    {
        cout << "Minimum Spanning Tree: " << i+1 << endl;
        cout << "Number of Nodes: " << treeData[i] << endl << endl;
	}
}

//***************************************************************************
//					  Class DisjointSet Method: Union
//                          Parameters: int set1_value, int set2_value
//							 Returns: None
//						  Complexity: O(n)
//
// Unions by rank two sets using path compression and union by rank. The path
// compression loop checks the entire parent array and defines the complexity
// of this method.
//***************************************************************************



void DisjointSet::Union (int set1_value, int set2_value)
{
    int set1_representative = parentArray[set1_value];
    int set2_representative = parentArray[set2_value];
    int newParent, oldParent;
    
    if (set1_representative != set2_representative)
    {
        if (set1_representative < set2_representative) // Union by rank
        {
           newParent = set1_representative;
           oldParent = set2_representative;
        }
        else
        {
            newParent = set2_representative;
            oldParent = set1_representative;
        }
        for (int i=0; i<max_nodes; ++i) // Path compression
        {
            if (parentArray[i] == oldParent)
                parentArray[i] = newParent;
        }
        
    }
    
}

//***************************************************************************
//					  Class DisjointSet Method: Find_Set
//                          Parameters: int value
//							 Returns:int
//						  Complexity: O(1)
//
// Returns the representative/parent of the set that the value belongs to.
// This is an O(1) operation.
//***************************************************************************


int DisjointSet::Find_Set(int value)
{
    return parentArray[value];
}



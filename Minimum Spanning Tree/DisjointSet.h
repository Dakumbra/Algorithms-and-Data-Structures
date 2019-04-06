
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet
{
    vector<int> parentArray;
    int max_nodes = 5241;
    
public:
    
    DisjointSet(); // Default Constructor
    void PrintParentArray(); // Print out Parent Array
    void ProjectPrint(); // Print out requirements for project
    void Union (int set1_representative, int set2_representative); // Combine two sets
    int Find_Set (int value); // Return Set Representative
    
};

//***************************************************************************
//                      Project #4 - Minimal Spanning Trees
//                              Name:  Samuel Weems
//                           Course:  CMPS 5243, Spring 2018
//                         Professor: Dr. Richard P. Simpson
//                              Date: May 02, 2018
//***************************************************************************
//                                  Introduction
//
//  In this project we took in data from the Stanford Network Analysis
//  Platform (https://snap.stanford.edu/data/ - file: ca-GrQc under
//  Collaboration networks). This data (used as a list of edges) was used
//  along with Kruskal's algorithm to generate Minimum Spanning Trees (MST's)
//  for the data set. IDs are reassigned to a range of 0 to 5241 before
//  running operations.
//
//***************************************************************************
//                              Program Complexity
//                                  O(n log n)
//
//  The program's overall complexity is based on the most complex call which
//  is the sort algorithm from the standard template library. That algorithm
//  has a complexity of O(n log n). All other methods are either O(n) or O(1).
//
//***************************************************************************
//
//  I have written the entire program as turned in and have not copied this
//  code, or parts of this code from the internet or another student.
//
//                                  Signature _______________________________
//
//***************************************************************************

#include "Graph.h"
#include <fstream>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>

int main(){

    ifstream inputFile;
    vector<tuple<int, int>> vertexData;  // Vector to gather original data pairs
    set<int> idSet;     // Set to gather distinct IDs in original data set
    vector<int> idArray; // Vector with indices for ID conversion
    
    inputFile.open("ca-GrQc.txt"); // Input file
    int vertex1, vertex2;
    
// Gather Data from File two vertices at a time
    
    while (inputFile >> vertex1)
    {
        inputFile >> vertex2;
        
        if (vertex1 < vertex2)   // Only choose one set of edges, no repeats
        {
            vertexData.push_back(make_tuple(vertex1, vertex2)); // Gather data pairs
            idSet.insert(vertex1); // Gather all IDs into Set (prevents duplicates)
            idSet.insert(vertex2);
        }
    }
    
    inputFile.close();
    
// Convert Set into an Array with indices (used for ID conversion)
	for (auto x : idSet)
		idArray.push_back(x);
    
// Create Graph
    
    Graph graph;
    
//Convert IDs and insert into Graph
    

    for (int i=0; i< vertexData.size(); ++i)
    {
        int v1 = get<0>(vertexData[i]);
        int v2 = get<1>(vertexData[i]);
        
        // Convert value to index number in idArray
        v1 = find(idArray.begin(), idArray.end(), v1) - idArray.begin();
        v2 = find(idArray.begin(), idArray.end(), v2) - idArray.begin();
        
        graph.AddEdge((abs(v1-v2)), v1, v2); // Add edges and weights
    }

// Calculate Minimal Spanning Trees and print output
    
    graph.MST();

    return 0;
}




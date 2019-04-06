#include "Graph.h"

//***************************************************************************
//					  Class Graph Method: AddEdge
//				 Parameters: int weight, int vertex1, int vertex2
//							Returns: None
//						   Complexity: O(1)
//
// Adds a new edge from one vertex to another with given weight.
//***************************************************************************

void Graph::AddEdge(int wt, int vertex1, int vertex2)
{
    edgeData.push_back(make_tuple(wt, vertex1, vertex2));
}

//***************************************************************************
//					   Class Graph Method: edgeOrder
//                          Parameters: None
//							 Returns: None
//						 Complexity: O(n log n)
//
// Uses standard template library sort algorithm to sort edges in ascending
// order according to first element (edge weight).
//***************************************************************************

void Graph::edgeOrder(){
     sort(edgeData.begin(), edgeData.end());
    
}

//***************************************************************************
//					     Class Graph Method: MST
//                          Parameters: None
//							 Returns: None
//						 Complexity: O(n log n)
//
// Calculates the minimum spanning trees using Kruskal's algorithms and calls
// project print method. The sort method from the stl called in edgeOrder() and
// ProjectPrint() define the complexity of this method.
//***************************************************************************

void Graph::MST(){

    // Order edges according to weight

    edgeOrder(); // n log n

    // Creates forests of Minimal Spanning Trees (MST) using Kruskal

    for (auto edge:edgeData)
    {
        int vertex1 = get<1>(edge);
        int vertex2 = get<2>(edge);

        if ((forest.Find_Set(vertex1)) != (forest.Find_Set(vertex2)))
            forest.Union(vertex1, vertex2);
    }
    
    // Prints project requirements
    forest.ProjectPrint();
}



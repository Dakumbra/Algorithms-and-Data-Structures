#include "DisjointSet.h"
#include <tuple>

class Graph
{
    vector<tuple<int, int, int>> edgeData; // weight, vertex1, vertex2
    DisjointSet forest;

public:
	void AddEdge(int from, int to, int wt);
    void edgeOrder(); // puts edges in order according to weight
    void MST(); // Calculates and ouputs Minimum Spannign Tree data
};


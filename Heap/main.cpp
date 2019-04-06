//***************************************************************************
//                   Project #4 - Priority Queue - UVa Problem 10954
//                              Name:  Samuel Weems
//                          UVa Login: Melchizedek, 929055
//                           Course:  CMPS 3013, Fall 17
//                         Professor: Dr. Richard P. Simpson
//                              Date: November 10 2017
//***************************************************************************
//                                  Introduction
//
//  This project uses a heap class (min heap) to implement a priority queue.
//  The heap (a vector) maintains the smallest element at the top of the
//  object. The main program takes a series of numbers, puts them into the min
//  heap structure. It then extracts the top 2 smallest numbers, adds them,
//  and reinserts the new value. Each sum is kept in an overall sum which is
//  reported as the "cost".
//
// The problem as described by the UVa website is to take a series of integers
// and find the lowest "cost" of summing these numbers with single summation
// operations. For example 1+2=3 has a cost of 3. 1+5=6 has a cost of 6.
// The lowest cost is achieved by the process described above.
//
//***************************************************************************
//                              Program Complexity
//									  O(n log n)
//
//  Heapify is the limiting factor in this program has the highest complexity.
//
//***************************************************************************
//
//  I have written the entire program as turned in and have not copied this
//  code, or parts of this code from the internet or another student.
//
//                                  Signature _______________________________
//
//***************************************************************************


#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//***************************************************************************
//                          Minimum Heap Class
//
//  A complete binary tree that is implemented as an array (vector).
//  The value of each node is at least the value of its parent.
//  The root of the tree, index 1, maintains the smallest value.
//  Index 0 stores size of the tree.
//
//***************************************************************************

class Heap
{
    vector<int> heap;
    
//***************************************************************************
//						Class Heap Method: Heapify
//					    Parameters: int currentIndex
//							  Returns: None
//						  Complexity: O(log n)
//
//  Maintains the heap property described above by comparing a node with its
//  children, switching values when appropriate, and then recursively calling
//  itself if a swap is made to maintain heap property down through the object
//
//***************************************************************************

    
    void heapify(int currentIndex)
    {
        int smallestIndex;
        int leftChildIndex = leftChild(currentIndex);
        int rightChildIndex = rightChild(currentIndex);
        
        if (leftChildIndex <= heapSize() && heap[leftChildIndex] < heap[currentIndex])
            smallestIndex = leftChildIndex;
        else
            smallestIndex = currentIndex;
        
        if (rightChildIndex <= heapSize() && heap[rightChildIndex] < heap[smallestIndex])
            smallestIndex = rightChildIndex;
        
        if (smallestIndex != currentIndex)
        {
            swap(heap[currentIndex], heap[smallestIndex]);
            heapify(smallestIndex);
        }
    }
    
//***************************************************************************
//			Class Heap Methods: parent,leftChild,rightChild
//					    Parameters: int i
//						 Returns: integer
//					    Complexity: O(1)
//
//  These methods use heap properties to return parent node, left child or
//  right child node indices respectively.
//
//***************************************************************************
    
    
    int parent (int i)
    {
        return (i>>1);
    }
    
    int leftChild (int i)
    {
        return (i<<1);
    }
    
    int rightChild (int i)
    {
        return ((i<<1)+1);
    }
    
    
public:
    
//***************************************************************************
//                       Class Heap Method: Heap()
//                           Parameters: None
//                             Returns: None
//                           Complexity: O(1)
//
//  Default constructor creates a heap class object and creates the first
//  node, index 0, with a value of 0 which is the current size before any
//  new values are inserted.
//
//***************************************************************************
    
    Heap(){
        heap.push_back(0);
    }
    

//***************************************************************************
//			Class Heap Methods: Heap(vector<int> array)
//					    Paramaters: vector
//						 Returns: None
//					 Complexity: O(n log n)
//
//  Overloaded constructor that builds a new heap object by being passed an
//  unsorted vector. The method creates index 0 to hold the size and then
//  puts the new values into a vector which then calls heapify (previous
//  method) to put into array into appropriate order.
//
//***************************************************************************
    
    
    Heap(vector<int> array)
    {
        heap.push_back(0);
        
        for (auto& x:array)
            heap.push_back(x);
        
        heap[0] = int(array.size());
        
        for (int i= (heapSize()/2); i>=1; --i)
            heapify(i);
    }
    
//***************************************************************************
//                  Class Heap Method: heapSize()
//					    Paramaters: none
//						 Returns: integer
//					    Complexity: O(1)
//
//  This method returns the size of the vector / heap. The size is held in
//  index 0 of the vector/heap.
//
//***************************************************************************
    
    int heapSize()
    {
        return heap[0];
    }
    
//***************************************************************************
//              Class Heap Method: insert(int value)
//					    Paramaters: int value
//						 Returns: None
//					    Complexity: O(log n)
//
//  This method inserts a new value into the heap structure. It does so by
//  adding the new value to the end of the vector and then testing its value
//  with parent nodes until it is in the right location (not less than its
//  parent's value).
//
//***************************************************************************
    
    void insert (int value)
    {
        heap.push_back(value);
        ++heap[0];
        
        int currentLocation = heapSize();
        int testLocation = parent(currentLocation);
        int tempValue;
        
        while ((testLocation>0) && (heap[currentLocation] < heap[testLocation]))
        {
            tempValue = heap[testLocation];
            heap[testLocation] = heap[currentLocation];
            heap[currentLocation] = tempValue;
            currentLocation = testLocation;
            testLocation = parent(currentLocation);
        }
        
    }
    
//***************************************************************************
//                 Class Heap Method: Extract()
//					    Paramaters: None
//						 Returns: integer
//					    Complexity: O(log n)
//
//  This method removes the top of the heap (index 1) which in this
//  implementation is the minimum value. The method stores the root of the
//  tree (minimum value/index 1) to return as the extracted value. It then
//  swaps that value with the last value of the vector and deletes the last
//  element of the vector (also adjusting size). The new root is then passed
//  to heapify so that it is passed down to the appropriate location.
//
//***************************************************************************
    
    int Extract()
    {
        if (heapSize() > 0)
        {
            int min = heap[1];
            swap(heap[1], heap[heapSize()]);
            
            heap.pop_back();
            --heap[0];
            
            heapify(1);
            return min;
        }
        else
            return 0;
    }
};


//***************************************************************************
// Main Program
//***************************************************************************
    
int main()
{
    ifstream inputFile;
    ofstream outputFile;
    
    inputFile.open("data.txt");
    outputFile.open("output.txt");
    
    int arraySize, input, newValue, value1, value2, cost;
    
    while (inputFile >> arraySize)
    {
        cost = 0;
        Heap array;
        
    
        for (int i=0; i<arraySize; i++)
        {
            inputFile >> input;
            array.insert(input);
        }
    
        
        while (array.heapSize() > 1)
        {
            value1 = array.Extract();
            value2 = array.Extract();
            
            newValue = value1 + value2;
            cost += newValue;
            
            array.insert(newValue);
  
        }
        
        if (arraySize != 0)
            outputFile << cost << endl;
    }
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}





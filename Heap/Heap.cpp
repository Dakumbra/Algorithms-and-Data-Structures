

// Max Heap

//***************************************************************************

#include "Heap.h"
#include <iostream>
#include <algorithm>


// Private Methods
//***************************************************************************


// Maintains the heap property by adjusting the heap vector appropriately

void Heap::heapify(int currentIndex)
{
    int largestIndex;
    int leftChildIndex = leftChild(currentIndex);
    int rightChildIndex = rightChild(currentIndex);
    
    if (leftChildIndex <= heapSize() && heap[leftChildIndex] > heap[currentIndex])
        largestIndex = leftChildIndex;
    else
        largestIndex = currentIndex;
    
    if (rightChildIndex <= heapSize() && heap[rightChildIndex] > heap[largestIndex])
        largestIndex = rightChildIndex;
    
    if (largestIndex != currentIndex)
    {
        swap(heap[currentIndex], heap[largestIndex]);
        heapify(largestIndex);
    }
}


// Returns parent node

int Heap::parent (int i)
{
    return (i>>1);
}

int Heap::leftChild (int i)
{
    return (i<<1);
}

int Heap::rightChild (int i)
{
    return ((i<<1)+1);
}



// Public Methods
//***************************************************************************

// Default Constructor stores 0 (size) in first node

Heap::Heap(){
    heap.push_back(0);
}

// Constructor that builds a heap from an unsorted vector arry

Heap::Heap(vector<int> array)
{
    heap.push_back(0);
    
    for (auto& x:array)
        insert(x);
}

// Returns size of the Heap

int Heap::heapSize()
{
    return heap[0];
}

// Insert new value into Heap and then move it up in list to appropriate place

void Heap::insert (int value)
{
    heap.push_back(value);
    ++heap[0];
    
    int testLocation = heapSize()-1;
    int currentLocation = heapSize();
    int tempValue;
    
    while ((testLocation>0) && (heap[currentLocation] > heap[testLocation]))
    {
        tempValue = heap[testLocation];
        heap[testLocation] = heap[currentLocation];
        heap[currentLocation] = tempValue;
        --testLocation;
        --currentLocation;
    }
    
}

// Extracts top of heap (greatest value) from heap

int Heap::Extract()
{
    if (heapSize() > 0)
    {
        int max = heap[1];
        swap(heap[1], heap[heapSize()]);
        
        heap.pop_back();
         --heap[0];
        
        heapify(1);
        return max;
    }
    else
        return 0;
}


// Prints entire heap array

void Heap::print()
{
    for (int i=0; i<heapSize()+1; i++)
        cout << i << ": " << heap[i] << endl;
}

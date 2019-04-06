
//***************************************************************************

#include <vector>

using namespace std;

class Heap
{
    vector<int> heap;
    
    void heapify(int currentIndex);
    int parent (int i);
    int leftChild (int i);
    int rightChild (int i);
  
public:
    
    Heap();
    Heap(vector<int> array);
    int heapSize();
    void insert(int value);
    int Extract();
    
    void print();
    
    
    
    
    
};

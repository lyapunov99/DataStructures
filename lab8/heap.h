#include <iostream>
#include <sstream>

using namespace std;

class Heap {
  
 public:
  
  //Build empty heap
  Heap();
  
  //Builds a heap from list
  Heap(int list[], int listSize);
  
  //not used for this lab
  void insert(int x);
  
  //removes the smallest element in the heap
  int remove();
  
  //returns the size of the heap;
  int size();
  
 private:
  
  //heap is implemented as an array of 25 ints 
  //better implementation would be a dynamic array
  int heap[25];
	
  //number of elements currently in the heap
  int heapSize;
  
  //down heap function
  void downHeap(int location);
  
  //up heap function for insert
  void upHeap(int location); 
  
  //build heap function used by constructor that takes in array
  void buildHeap();
  
  int leftChild(int index);
  int rightChild(int index);
  int parent(int index);
};


#include "heap.h"

Heap::Heap()
{
  heapSize = 0;
}

Heap::Heap(int list[], int listSize)
{
  // YOUR CODE HERE
  heapSize = listSize;
  buildHeap();  
}

void Heap::insert(int x)
{
  // YOUR CODE HERE
}

int Heap::remove()
{
  // YOUR CODE HERE  
}

int Heap::size()
{
  return heapSize;
}

void Heap::downHeap(int location)
{
  // YOUR CODE HERE
}

void Heap::upHeap(int location)
{
  // coming soon as it gives away the answer to heapify
}	

void Heap::buildHeap()
{  
  // YOUR CODE HERE 
}

int Heap::leftChild(int index)
{
  // YOUR CODE HERE
}

int Heap::rightChild(int index)
{
  // YOUR CODE HERE
}

int Heap::parent(int index)
{
  // YOUR CODE HERE
}

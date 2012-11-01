#define DEFAULT_SIZE 1000

#include <iostream>

using namespace std;

template <typename T>
class PQ
{
 public:
  PQ();
  PQ(int size);
  bool isEmpty();
  bool isFull();
  void enqueue(T val);
  T dequeue();
  ~PQ();
 private:
  T *heap;
  int top;
  int size;
  
  // Description: move an element up in the heap until it fits
  // Precondition: element at pos exists
  // Postcondition: return the position it moved to
  int bubbleUp (int pos);
  
  // Description: move an element down in the heap until it fits
  // Precondition: element at pos exists
  // Postcondition: return the position it moved to    
  int bubbleDown (int pos);
};

template <typename T>
PQ<T>::~PQ()
{
  delete [] heap;
}

template <typename T>
PQ<T>::PQ()
{
  heap = new T[DEFAULT_SIZE];
  size = DEFAULT_SIZE;
  top = 0;
}

template <typename T>
PQ<T>::PQ(int size)
{
  heap = new T[size];
  this->size = size;
  top = 0;
}

template <typename T>
int PQ<T>::bubbleUp(int pos)
{
  return 0; // placeholder
}

template <typename T>
int PQ<T>::bubbleDown(int pos)
{
  return 0; // placeholder
}

template <typename T>
bool PQ<T>::isEmpty()
{
  if (top == 0) {
    return true;
  }
  else {
    return false;
  }
}

template <typename T>
bool PQ<T>::isFull()
{
  if (top == size) {
    return true;
  }
  else {
    return false;
  }
}

template <typename T>
void PQ<T>::enqueue(T val)
{
  if (!isFull()) {
    heap[top] = val;
    top++;
  }
}

template <typename T>
T PQ<T>::dequeue()
{
  if (!isEmpty()) {
    T temp = heap[0]; // HINT: this doesn't work!
    top--;
    return temp;
  }
  cerr << "You are about to receive junk..." << endl;
  return heap[0]; // bah!
}

#ifndef lab8_Heap_h
#define lab8_Heap_h

#define DEFAULT_SIZE 1000

template <typename T>
class Heap
{
public:
    // Description: Initializes heap
    // Precondition: Heap does not exist
    // Postcondition: Initialize heap with default size
    Heap();
    
    // Description: Initializes heap
    // Precondition: Heap does not exist
    // Postcondition: Initialize heap with default size
    Heap(int size);
    
    // Description: swap two heap elements
    // Precondition: elements i and j exists
    // Postcondition: elements at i and j are swapped
    void swap(int i, int j);
    
    // Description: move an element up in the heap until it fits
    // Precondition: element at pos exists
    // Postcondition: return the position it moved to
    int bubbleUp (int pos);
    
    // Description: move an element down in the heap until it fits
    // Precondition: element at pos exists
    // Postcondition: return the position it moved to    
    int bubbleDown (int pos);
    
    // Description: checks if heap is empty
    // Precondition: heap is defined
    // Postcondition: returns true if heap is empty, else false
    bool isEmpty();
    
    // Description: checks if heap is full
    // Precondition: heap is defined
    // Postcondition: returns true if heap is full, else false
    bool isFull();
    
    // Description: inserts an element into end of heap and bubble up
    // Precondition: heap is defined
    // Postcondition: if heap is not full, put element into end of heap and bubble up
    void enqueue(T val);

    // Description: removes highest numbered element from heap
    // Precondition: heap is defined
    // Postcondition: if heap is not empty, remove root element and bubble down
    T dequeue();
    
    // Description: deletes heap from memory
    // Precondition: heap is defined
    // Postcondition: invalidates heap from memory
    ~Heap();
private:
    T *heap;
    int top;
    int size;
};

template <typename T>
Heap<T>::~Heap()
{
    delete [] heap;
}

#endif

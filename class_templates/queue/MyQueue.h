//
//  MyQueue.h
//  Genericity
//
//  Created by Ming Chow on 10/3/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#ifndef Genericity_Queue_h
#define Genericity_Queue_h

template <class T>
class MyQueue
{
public:
    MyQueue();
    MyQueue(int n);
    void enqueue(T item);
    T dequeue();
    bool isEmpty();
    bool isFull();
    ~MyQueue();
private:
    int maxSize;
    int currentSize;
    T *queue;
};

template <class T>
MyQueue<T>::MyQueue()
{
    queue = new T[1000];
    maxSize = 1000;
    currentSize = 0;
}

template <class T>
MyQueue<T>::MyQueue(int n)
{
    if (n < 0) {
        maxSize = 1000;
    }
    else {
        maxSize = n;
    }
    queue = new T[maxSize];
    currentSize = 0;
}

template <class T>
bool MyQueue<T>::isEmpty()
{
    return currentSize == 0;
}

template <class T>
bool MyQueue<T>::isFull()
{
    return currentSize == maxSize;
}

template <class T>
void MyQueue<T>::enqueue(T item)
{
    if (!isFull()) {
        queue[currentSize] = item;
        currentSize++;
    }
}

template <class T>
T MyQueue<T>::dequeue()
{
    T returnVal;
    if (!isEmpty()) {
        returnVal = queue[0];
        for (int count = 0; count < currentSize - 1; count++) {
            queue[count] = queue[count + 1];
        }
        currentSize--;
    }
    return returnVal;
}

template <class T>
MyQueue<T>::~MyQueue()
{
    delete [] queue;
}

#endif

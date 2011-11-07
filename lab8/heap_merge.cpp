#include <iostream>
#include <sys/time.h>
#include "Heap.h"

using namespace std;

void mergeList(int v[], int leftStart, int leftEnd, int rightStart, int rightEnd);
void mergeSort(int v[], int start, int end); // first = index of first value in array, last = index of last value in array

// Description: Merges two "lists" together provided start and end indices of left and right lists
void mergeList(int v[], int leftStart, int leftEnd, int rightStart, int rightEnd)
{
    int *temp;
    int saveFirst, index;
    
    index = leftStart;
    saveFirst = leftStart;
    temp = new int[leftStart + rightEnd + 1];
    while ((leftStart <= leftEnd) && (rightStart <= rightEnd)) {
        if (v[leftStart] < v[rightStart]) {
            temp[index] = v[leftStart];
            leftStart++;
        }
        else {
            temp[index] = v[rightStart];
            rightStart++;
        }
        index++;
    }
    while (leftStart <= leftEnd) {
        temp[index] = v[leftStart];
        leftStart++;
        index++;
    }
    while (rightStart <= rightEnd) {
        temp[index] = v[rightStart];
        rightStart++;
        index++;
    }
    for (int count = saveFirst; count <= rightEnd; count++) {
        v[count] = temp[count];
    }
    delete [] temp;
}

int main()
{
    // The initial vector
    int inputs[10] = {3, 13, 18, 12, 4, 9, 3, 2, 20, 5};

    // For timing
    timeval start, end;
    double elapsedTime;

    // Heap sorting
    Heap <int> h;
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10; i++) {
        h.enqueue(inputs[i]);
    }
    gettimeofday(&end, NULL);
    elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0; // sec to ms
    elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0; // us to ms
    while (!h.isEmpty()) {
        cout << h.dequeue() << " ";
    }
    cout << endl;
    cout << "Elapsed time of heap sort(ms): " << elapsedTime << "ms" << endl;
    cout << "Elapsed time of heap sort(s): " << elapsedTime / 1000.0 << "s" << endl;
    
    // Merge sorting
    gettimeofday(&start, NULL);
    mergeSort(inputs, 0, 9);
    gettimeofday(&end, NULL);
    for (int count = 0; count < 10; count++) {
        cout << inputs[count] << " ";
    }
    cout << endl;
    elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0; // sec to ms
    elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0; // us to ms
    cout << "Elapsed time merge sort(ms): " << elapsedTime << "ms" << endl;
    cout << "Elapsed time merge sort(s): " << elapsedTime / 1000.0 << "s" << endl;    
    return 0;
}

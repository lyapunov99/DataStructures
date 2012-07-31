#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    int inputs[10] = {3, 13, 18, 12, 4, 9, 3, 2, 20, 5};
    Heap <int> h;
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10; i++) {
        h.enqueue(inputs[i]);
    }

    while (!h.isEmpty()) {
        cout << h.dequeue() << " ";
    }
}

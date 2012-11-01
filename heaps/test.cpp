#include <iostream>
#include "PQ.h"

using namespace std;

int main()
{
  int inputs[10] = {3, 13, 18, 12, 4, 9, 77, 2, 20, 5};
  
  PQ <int> h;
  for (int i = 0; i < 10; i++) {
    h.enqueue(inputs[i]);
  }
  while (!h.isEmpty()) {
    cout << h.dequeue() << " ";
  }
  cout << endl;
  return 0;
}

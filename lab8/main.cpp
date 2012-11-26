#include "heap.h"

void heapSort(int list[], int size)
{
  int* temp;
  temp = new int[size];
  
  Heap h(list,size);
  for (int i=0; i < size; i++) {
    temp[i] = h.remove();
  }
  
  for(int j=0; j < size; j++) {
      list[j] = temp[j];
  }
}

int main()
{
  int testList[] = {34, 5, 23, 12, 33, 98, 4, 13, 44, 37, 1, 86, 8}; 
  int size = 13;
  
  heapSort(testList, size);
  cout << "Lists should match " << endl;
  cout << "1, 4, 5, 8, 12, 13, 23, 33, 34, 37, 44, 86, 98" << endl;
  
  for(int i=0; i < size; i++) {
    cout << testList[i] << ", ";
  }
  cout << endl;
  return 0;
}

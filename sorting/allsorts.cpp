#include <iostream>
#define MIN_QSORT_SIZE 4
using namespace std; 


// variable arr must be an array of length len
//
void printarr(int arr[], int len) { 
  for (int i =0; i < len; i++) { 
    cout << arr[i] << " ";
  }
  cout << endl; 
}

// used to swap array elements in the sort functions 
// precondition: the length of a[] must be at least max(p1,p2)+1 
//       (in other words, a[p1] and a[p2] must exist)
// postcondition:  the p1-st and p2-nd elements in a[] have been swapped.
//
void swap(int a[], int p1, int p2) { 
  int temp;
  temp = a[p1];
  a[p1]=a[p2];
  a[p2]=temp;
}


// precondition:  a is an array of ints, and a[lo] and a[hi] exist
// postcondition:  a[lo..hi] are sorted in increasing order
// note:  need indices lo and hi to use this as a subroutine of quicksort
//
void insertSort(int a[],int lo, int hi) { 

  // invariant:  a[lo..i] is sorted
  // result:  a[lo..hi] is sorted
  int i = lo; 
  while (i < hi) { 
    i++; // break invariant, then insert the ith elt in proper place:
    int j = i-1; // count from here down to lo and swap if needed
    while (j >= lo && a[j] > a[j+1]){ 
      swap(a,j,j+1);
      j--;
    }
    // invariant holds again
  }
}

// used by the mergeSort function
// precond:
//   a[0..len1-1] is a sorted subarray w length len1
//   and (a+len1)[len1..len2-1] is a sorted subarray w length len2
// postcond:  
//   a[0..(len1 + len2 -1)] is sorted
// 
void merge(int a[], int len1, int len2) {
  int* temp; 
  temp = new int[len1+len2]; 

  int fromFirst = 0; // number copied from first part 
  int fromSecond=0;  // number copied from second part
  int inTemp=0; // total number copied into temp so far

  while ( fromFirst < len1 && fromSecond < len2) { 
    if (a[fromFirst] < (a+len1)[fromSecond]) { 
      // copy from first half
      temp[inTemp] = a[fromFirst]; 
      fromFirst++;
    }
    else { // copy from second half
      temp[inTemp] = (a + len1)[fromSecond]; 
      fromSecond++; 
    }
    inTemp++;  // either way, increment number in temp array
  }

  // finish rest of the arrays
  while (fromFirst < len1) { 
    temp[inTemp++] = a[fromFirst]; 
    fromFirst++; 
  }
  while (fromSecond < len2) { 
    temp[inTemp++] = (a+len1)[fromSecond]; 
    fromSecond++;
  }

  // then copy all back into a[]
  for( int i=0; i < len1+len2; i++) { 
    a[i] = temp[i]; 
  }
  delete [] temp; // and free temp
}


// precond:  a[lo..hi] is an array of ints
// postcond:  a[lo..hi] is sorted
//
void mergeSort(int a[],int len) { 

  if (len<=1) {
    return; 
  }
  int len1, len2; 
  len1 = len/2; 
  len2 = len - len1; 
  mergeSort(a,len1); 
  mergeSort((a+len1), len2); 
  merge(a, len1, len2); 
    //  merge(a,lo,mid-lo+1,hi-mid+1);
}

// precond: a[lo..hi] is an array of ints
// postcond: pivot is in correct place and all to left are less, all to right, greater
// returns: index of pivot
//
int partition(int a[], int lo,int hi) {  

  int toobig, toosmall;
  int pivot = a[lo];

  toobig = lo+1; 
  toosmall = hi;  // know that toosmall is to right of toobig because else would insSort()
  while (toobig <= toosmall) { 

    while (a[toobig] < pivot && toobig <= hi)  
      toobig++;  // stop when find one that is really too big for the left side
                 // dont run off the end, though

    while (a[toosmall] > pivot)  
      toosmall--;  // stop when find one that is really too small for the right side
                   // if get to end of array, will find pivot itself but will also cross 

    if (toobig < toosmall) {
      swap(a,toobig,toosmall); 
      toobig++; // move along 
      toosmall--; 
    }
  }

  swap(a,lo,toosmall);  // put pivot into right place
  return toosmall;  // current loc of pivot
}


// precondition:  a is an array of ints, and a[lo] and a[hi] exist
// postcondition:  a[lo..hi] are sorted in increasing order
//
void quickSort(int a[], int lo, int hi) { 

  int pivot;
  
  if (lo == hi) {  // if a single element list, done
    return;  
  }
  if (hi-lo+1 < MIN_QSORT_SIZE) {
    insertSort(a, lo, hi); 
  }
  else { 
    pivot = partition(a,lo,hi); 
    if (pivot - 1 > lo)   
      quickSort(a, lo, pivot-1);
    if (pivot+1 < hi) 
      quickSort(a, pivot+1, hi);
  }

}


int main() { 

  // should insert multiple tests here, but these are the current examples

  int len = 17;
  int a[] = {82,15,4,11,93,52,73,12,33,87,29,45,71,16,31,61,26}; 
  int b[] = {82,15,4,11,93,52,73,12,33,87,29,45,71,16,31,61,26};   
  printarr(a,len); 
  quickSort(a,0,len-1); 
  printarr(a,len); 

  printarr(b,len);
  mergeSort(b,len); 
  printarr(b,len);


  return 0;
}

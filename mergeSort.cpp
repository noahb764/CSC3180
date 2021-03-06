// Second Programming Assignment - Sam Bystrek, Noah Bass
// Code for merge sort from - https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort
// Average time between merge and quick sorts = mergeSort (.158s difference) and quickSort(0.19 difference)

#include<iostream>
#include <ctime>
using namespace std;
void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main() {
  srand(time(0));
  int n = 1000;
  int arr[n];     //create an array with given number of elements
  for(int c = 0; c<101; c++)
    {
      for(int i = 0; i<n; i++)
	{
	  arr[i] = rand()%1000+1;
	}

      cout << endl;
      cout << "Array before Sorting: ";
      cout << endl;
      display(arr, n);
      mergeSort(arr, 0, n-1);     //(n-1) for last index
      cout << endl;
      cout << "Array after Sorting: ";
      display(arr, n);
    }
  return 0;
}

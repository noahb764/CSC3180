// Sam Bystrek, Noah Bass

// Team Programming Assignment Two

// define int size = 1000

// NOTE: We can set the array size via an enhanced for loop defining the array's size
// Example: int array[size]
// 	    for(int i = 0; i < size; i++)
// 	    {
// 	    	const int arraySize = 1000;
// 	    }

#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;


int partition(int *array, int p, int q) // p = left; q = right
{
	int x = array[p];
	int i = p; // Assign left array to index
	x = q; // Assign right array to pivot

	for(int j = p; j <= q; j++)
	{
		if(array[j] < array[x])
		{
			swap(array[j], array[i]);
			i++;
		}
	}
	
	swap(array[x], array[i]);
	return i;
}

/*void merge(int array[], int p, int mid, int q) 
{
  //cout << "left" << p << endl;
  //cout << "right" << q << endl;
  //cout << "mid" << mid << endl;

   int i, j, new_Mid, new_P, new_Q;
  // new_Mid = 0;
   //size of left and right sub-arrays
   
   new_P = mid - p + 1; new_Q = q - mid;
   
   int Parr[new_P], Qarr[new_Q];
   
   //fill left and right sub-arrays
   
   for(i = 0; i < new_P; i++)
   {
      Parr[i] = array[p + i];
   }
   
   for(j = 0; j < new_Q; j++)
   {
      Qarr[j] = array[mid + 1 + j];
   }
  cout << "Put data in arrays" << endl; 
   i = 0; j = 0; new_Mid = new_P;

   //merge temp arrays to real array
   while(i < new_P && j < new_Q) 
   {
      if(Parr[i] <= Qarr[j]) 
      {
         array[new_Mid] = Parr[i];
         i++;
      }
      
      else
      {
         array[new_Mid] = Qarr[j];
         j++;
      }
	new_Mid++;
   }
   cout << "Finished first while" << endl;
   while(i < new_P) 
   {       //extra element in left array
      array[new_Mid] = Parr[i];
      i++; 
      new_Mid++;
   }
   while(j < new_Q) 
   {     //extra element in right array
      array[new_Mid] = Qarr[j];
      j++; 
      new_Mid++;
   }
}

void mergeSort(int array[], int p, int q)
{

	int mid;

	if(p < q)
	{

		mid = p + (q - p)/2;

      	// Sort first and second arrays
//      cout << "First call MergeSort()" << endl;

		 mergeSort(array, p, mid);
  //    cout << "Second call MergeSort()" << endl;
	 	mergeSort(array, mid + 1, q);
    //  cout << "Calling Merge" << endl;
	 	merge(array, p, mid, q);
	}
}
*/

/*void merge(int array[], int p, int m, int q) // p = left, q = right
{
  



}
*/

void quickSort(int *array2, int p, int q) // p = left; q = right
{
	int middle;

	if(p < q)
	{
		middle = partition(array2, p, q);

		quickSort(array2, p, middle - 1);
		quickSort(array2, middle + 1, q);
	}
}

int main()
{
	const int arraySize = 1000;
	int array1[arraySize];
	int array2[arraySize];
	bool isDuplicate = 0;
	srand(time(0));

	for(int i = 0; i < arraySize; i++)
	{
		int temp = rand() % 100 + 1;

		array1[i] = temp;
		array2[i] = temp;

		/*if(array2[i] == isDuplicate)
		{
			isDuplicate = true;
			delete[array2[i]]; // Deletes a duplicate element from array
		}*/
	}	
/*
	cout << "\nThe mergeSort list before sorting: " << endl;


	for(int i = 1; i <= arraySize; i++)
	  {
	    cout << array1[i - 1] << " ";
	    if(i % 10 == 0)
	      {
		cout << endl;
	      }
	      }
	
	mergeSort(array1, 0, arraySize - 1);

	cout << "\nThe mergeSort list after sorting: " << endl;

	for(int i = 1; i <= arraySize; i++)
	  {
	    cout << array1[i - 1] << " ";
	    if(i % 10 == 0)
	      {
		cout << endl;
	      }
	  }
*/

	cout << "\nQuickSort list before sorting: " << endl;
	
	for(int i = 1; i <= arraySize; i++)
	{
		cout << array2[i - 1] << " ";
		if(i % 10 == 0)
		{
			cout << endl;
		}
	}

	quickSort(array2, 0, arraySize);

	cout << "\nQuickSort list after sorting: " << endl;

	for(int i = 1; i <= arraySize; i++)
	{
		cout << array2[i - 1] << " ";
		if(i % 10 == 0)
		{
			cout << endl;
		}
	}

	
	return 0;
}

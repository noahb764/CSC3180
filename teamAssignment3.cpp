// Sam Bystrek, Noah Bass
// Form a heap and sort it using the heapify and heapSort functions


// Add a list of numbers to an array then heapify
// Initial Example:
// 100 | 5 | 10 | 15
// a[1] is the parent
// a[2], a[3] are children
// we know that this satisfies the essentially full
//    requirement because of the way we are
//    constructing it.
// we will need to prove parental dominance

#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &a, int &b) {     //swap the content of a and b              
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *ar, int size)
{
   for(int i = 0; i < size; i++)
      cout << ar[i] << " ";
   cout << endl;
}

void heapify(int *ar, int size, int i)
{
  // right now we only have one parent to worry about
  // we will need to adjust this eventually
  // test if root is bigger than left and right child
  int biggest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  cout << "\nThe root is: " << ar[i] << endl;
  
  cout << "Original Array" << endl;
  display(ar, size);

  cout << "Check Left Child" << endl;
  if (left < size)
    {
      if(ar[left] > ar[biggest])
	{
	  biggest = left;
	}
    }

  cout << "\nThe left child is: " << ar[left] << endl;

  cout << "\n\nCheck Right Child" << endl;
  if (right < size)
    {
      if(ar[right] > ar[biggest])
      {
	biggest = right;
      }
    }

  cout << "\nThe right child is: " << ar[right] << endl;
  
  if(biggest != i)
    {

      cout << "\nThe new biggest is: " << ar[biggest] << endl;
      
      swap(ar[i], ar[biggest]);

      heapify(ar, size, biggest);
    }
  display(ar, size);
  
}

void heapSort(int *ar, int size)
{
   for(int i = size/2-1; i >= 0; i--) // Starts at the end of the array and works in reverse order
    {
      heapify(ar, size, i);
    }
  for(int i = size - 1; i > 0; i--)
    {
      swap(ar[0], ar[i]);
      heapify(ar, i, 0);
    }
}


int main()
{
  int n = 100;

  int choice = 0;

  int counter = 0;
  
  int a[n];

  int temp;

  
  cout << "\nWelcome to the heaping program..." << endl;
  cout << "\nWhat would you like to do?\n\n\n";
  cout << "\n1. Insert values and select a size for the array\n";
  cout << "\n2. Exit program\n";
  cin >> choice;

  
  if(choice == 1)
    {
      cout << "\nEnter your values ending in -999: ";
      cin >> temp;
      
      
      for(int i = 0; temp != -999; i++)
	{
	  while(!cin)
	    {
	      cerr << "\nInvalid input. Input should only be an integer value. Please try again...\n";
	      cin.clear();
	      cin.ignore();
	      cin >> temp;
	    }
	      a[i] = temp;
	      counter = counter + 1;
	      cin >> temp;
	}
	
    }
  else if(choice == 2)
    {
      cout << "\nGoodbye...\n" << endl;
      return 0;
    }
  
  cout << "\n\n\nBack in Main, this should be a heap" << endl;
  n = counter;
  heapSort(a, n);
  cout << "Returning to main\n" << endl;
  display(a, n);
  
   return 0;
}

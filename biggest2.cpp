// Noah Bass

// biggest2.cpp

#include <iostream>
using namespace std;

int main()
{

  int array[10];

  int counter = 0;

  int largest = 0;

  for(int i = 0; i < 10; i++)
    {
      cout << "Enter 10 integers: ";
      cin >> array[i];

      counter = counter + 1;

      if(!array[i]) // Checks and validates that user only enters integers
	{
	  cerr << "ERROR! The value you just entered is not an integer. Please try again...\n";
	  cin.clear();
	  cin.ignore();
	  cin >> array[i];
	}

      if(array[i] > largest) // Basic Operation
	{
	  largest = array[i];
	}
    }
  
  cout << "The basic operation executed " << counter << " times.\n" << endl;
  
  cout << "The biggest integer is " << largest << endl;

  return 0;
}

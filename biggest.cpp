// Noah Bass

// biggest.cpp

#include <iostream>
using namespace std;

int main()
{

  int array[10];

  int largest = 0;

  for(int i = 0; i < 10; i++)
    {
      cout << "Enter 10 integers: ";
      cin >> array[i];

      if(array[i] > largest) // Basic Operation
	{
	  largest = array[i];
	}
    }
  
  cout << "The biggest integer is " << largest << endl;

  return 0;
}

// Noah Bass, Sam Bystrek

// Team Programming Assignment #1

// We used the point class as our .h file from www.cplusplus.com/forum/general/124555

#include <iostream>
#include "closestPoint.cpp"
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

int main()
{
  srand(time(0)); // Intializing timer
  int n = 0;
  double c = 0;  
  int p1;
  int p2;
  

  cout << "How many points would you like to have? (Must be 2 or more points)\n";
  cin >> n;

  while(!cin || n < 2) // Input Validation
    {
      cerr << "ERROR! The value entered was not an integer or was less than 2. Please try again...\n";
      cin.clear();
      cin.ignore();
      cin >> n;
    }
      
  closestPoint arr[n];

  for(int i = 0; i < n; i++) // Function to generate coordinates for each point (is between -100 to 100)
    {
      double temp = rand() % 201 - 100;
      cout << "Point #" << i + 1 << ": (" << temp << ", ";
      arr[i].setX(temp);
      temp = rand() % 201 - 100;
      cout << temp << ")" << endl;
      arr[i].setY(temp);
    }

  double closest = 20000;
  
  for(int i = 0; i < n - 1; i++) // Function to determine the distance
    {
      for(int j = i + 1; j < n; j++)
	{
	  c = sqrt(((arr[i].getX() - arr[j].getX()) * (arr[i].getX() - arr[j].getX())) + ((arr[i].getY() - arr[j].getY()) * (arr[i].getY() - arr[j].getY())));

	  if(c < closest)
	    {
	      closest = c;
	      p1 = i + 1;
	      p2 = j + 1;
	      cout << "The new closest is: " << c << endl;
	      
	    }

	}
    }

  // Print Statements
  
  cout << "\nThe closest points were " << closest << " in distance.\n" << endl;

  cout << "\nThe closest points were " << p1 << " and " << p2 << endl;
  
  return 0;
}

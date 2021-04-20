// Sam Bystrek, Noah Bass
// Dependencies are listed at the top of the program
// The program should take in user data, store that data, and allow the user to check for their values

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

bool search(list<string> HT[10], int userData)
{
  bool found;
  int newData; // Added variable to store the current userData

  newData = userData; // Assign the data stored in userData to newData

  while(newData > 10)
    {
      newData = newData % 10;
    }
  
  for (list<string>::iterator it = HT[newData].begin(); it != HT[newData].end(); it++)
    {
      cout << "\n\nValue of *it after entering the for loop" << endl;
      cout << *it << endl; // Testing the value of the iterator
      if(stoi(*it) == newData)
	{
	  cout << "\n\nValue of *it after comparing it to newData" << endl;
	  cout << *it << endl; // Testing the value of the iterator after comparing it to newData
	  found = true;
	}
    }
  return found;
}

int hashing(int input)
{
  //userData = new (int) input;
  while(input > 10) // Should give value between 0-9
    {
      input = input % 10;
    }
  
  return input;
}

int main()
{
  // List is just a data type.  As we could do
  // int a[10], we can do
  // we could create a list of ints with
  // list<int> l
  // So we will create an array of lists:
  
  list<string> HT[10]; // Initializing HashTable of size 10

  int userData = 0;

  int pos = 0;

  int choice = 0;
  
  for(int i = 0; i < 10; i++) // Prompt user to enter their data
    {
      cout << "\n\nEnter your data: ";
      cin >> userData;
 
      while(!cin) // Validate user input
	{
	  cerr << "\n\nERROR! The data you have entered is not an interger, nor is it a non-negative value. Please try again...\n\n";
	  cin.clear();
	  cin.ignore();
	  cin >> userData;
	}// End Validation Loop

      string userData2 = to_string(userData); // Copy userData to userData2

      //pos = HT[0].push_back(userData2);
      //HT[pos].push_back(userData2);
      
      HT[0].push_back(userData2); // Add data to the hash table

      HT[1].push_back(userData2); // Add data to the hash table
      
      HT[2].push_back(userData2); // Add data to the hash table
      
      HT[3].push_back(userData2); // Add data to the hash table
      
      HT[4].push_back(userData2); // Add data to the hash table
      
      HT[5].push_back(userData2); // Add data to the hash table
      
      HT[6].push_back(userData2); // Add data to the hash table
      
      HT[7].push_back(userData2); // Add data to the hash table
      
      HT[8].push_back(userData2); // Add data to the hash table
      
      HT[9].push_back(userData2); // Add data to the hash table

      
      while(choice) // Prompt user with more options
	{
	  cout << "\n\nWhat would you like to do next?";
	  cout << "\n\n1. Search the hash table for a value entered?\n";
	  cout << "\n\n2. Hash the data entered?\n";
	  cin >> choice;
  
	  if(choice == '1')
	    {
	      bool inHash = false;


	      inHash = search(HT, 0);
      
	  //search(HT[0], userData2);
	      if(inHash == true)
		{
		  cout << inHash << endl;
		}
	      else
		{
		  return -1;
		}
       
	    }
	  else if(choice == '2')
	    {
	      pos = hashing(userData);
	    }
	} // End choice loop
  
    } // End first while

  //HT[pos].push_back(userData);
  /* 
  bool inHash = false;
  inHash = search(list<string> HT[10], userData);
  cout << inHash << endl;
  */

  // add A, then B, then C to the first list in the array
  
  // HT[0].push_back("A");
  //HT[0].push_back("B");
  //HT[0].push_back("C");

  /*  // print out the list using iterators from <list>
  cout << "\nThe first linked list" << endl;

  for (list<string>::iterator it = HT[0].begin(); it != HT[0].end(); it++  )
    {
      cout << *it << endl;
    }

  // add X, then Y, then Z to the last list in the array
  
  HT[9].push_back("X");
  HT[9].push_back("Y");
  HT[9].push_back("Z");

  // print out the list using iterators from <list>
  cout << "\n\nThe last linked list" << endl;  
  for (list<string>::iterator it = HT[9].begin(); it != HT[9].end(); it++  )
    {
      cout << *it << endl;
    }  
  */
  
  return 0;
}

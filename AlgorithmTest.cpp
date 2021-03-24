// Noah Bass

// SortAnalysis(A[0..n-1])

// The random array generator isn't working properly. I tried working on it, but could not get it to work properly. Not sure what I am missing here?

// Update: Random array generator prints out random numbers, but not the way the program calls for

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  int random = 20;
  int a[random] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000};
  int count = {};
  int v = 0;
  int j = 0;

  for(int i = 1; i < i - 1; i++)
    {
      v = a[i];
      j = i - 1;

      while(j >= 0 && a[j] > v)
	{
	  a[j + 1] = a[j];
	  j = j - 1;
	}
      a[j + 1] = v;
    }

  count = count + 1; // The comparison counter was not in the right place. It should be outside of
                     // for loop in order to calculate the comparisons. Otherwise, since its a while                      // loop it will print out zero.

  srand((int)time(NULL));
  a[random] = rand()%100000;

  cout << a[random] << endl;
  cout << "The amount of key comparisons in this algorithm is: " << count << endl;

  return 0;
}

// Noah Bass

// Algorithm to find the closest pair

// Still a work in progress

#include <iostream>
#include <algorithm>
using namespace std; 

int closestPair(int p[], int q, int shortestPath, int n)
{
	if(n <= 3)
	{
		return shortestPath;
	}
	else
	{
		copy p[0], p[n-1/2];
		copy q[0], q[n-1/2];
		copy p[n-1], p[n+1];
		copy q[n-1], q[n+1];
	}
}

int main()
{


	return 0;
}

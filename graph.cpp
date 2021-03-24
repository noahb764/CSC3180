#include <iostream>
#include <list>
#include <algorithm>
#include <stack>
using namespace std;
class Graph {
private:
  int n;
  list<int> *adj;
  //Functions

public:
  Graph(int n); //constructor
  void addEdge(int v, int w);
  void printEdges();
  void printVertices();
};

Graph::Graph(int n)
{
   this->n = n;
   adj = new list<int> [n];
}

void Graph::printEdges()
{
  cout << "\n\nGraph Edges" << endl;
  list<int>::iterator i;
  for(int v = 0; v < n; v++)
    {
      for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
	  cout << v << " - " << *i << endl;
	}
    }
}

void Graph::printVertices()
{
  cout << "\n\nVertices" << endl;
  for (int v = 0; v < n; v++)
    {
      cout << v << endl;
    }
}
void Graph::addEdge(int v, int w) // add the edges to the graph.
{
   adj[v].push_back(w); //add w to v’s list
}

int main()
{
   Graph g(5);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 3);
   g.addEdge(2, 4);
   g.addEdge(3, 4);
   g.printVertices();
   g.printEdges();
   return 0;
}

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

class Graph
{
  int n;
  int **adj;

public:
  Graph(int v)
  {
    n=v;
    adj=new int*[v];
    for(int i=0; i<n; i++)adj[i]=new int[v];
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        adj[i][j]=0;
  }
  void addEdge(int v, int w)
  {
    this->adj[v][w]=1;
    this->adj[w][v]=1;
  }
  void BFS(int s)
  {
    bool visited[n];
    memset(visited, false, sizeof(visited[0]));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
      int curr=q.front(); q.pop();
      cout << curr << " ";
      for(int i=0; i<n; i++)
      {
        if(adj[curr][i]==1 && visited[i]==false){q.push(i); visited[i]=true;}
      }
    }
  }
};

int main()
{
  Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}

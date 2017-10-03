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

  void DFSUtil(int s, bool visited[])
  {
    visited[s]=true;
    cout << s << " ";

    for(int i=0; i<n; i++)if(adj[s][i]==1 && visited[i]==false)DFSUtil(i, visited);
  }

  void DFS(int s)
  {
    bool *visited=new bool[n];
    memset(visited, false, sizeof(visited[0]));

    DFSUtil(s, visited);
    cout << endl;
  }
};

int main()
{
  Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 3);
    g.addEdge(6, 4);
    g.addEdge(5, 6);

    g.DFS(2);

    return 0;
}

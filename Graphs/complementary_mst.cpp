#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;


struct edge{
  int weight;
  int src;
  int dest;
};

struct func2{
  bool operator()(edge s1, edge s2)
  {
    return s1.weight<s2.weight;
  }
};

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
  void addEdge(int v, int w, int k)
  {
    adj[v][w]=k;
    adj[w][v]=k;
  }

  void allDFSUtil(int g[100][100], int s, vector<bool> &visited, vector<int> &path)
  {
    visited[s]=true;
    path.push_back(s);

    if(path.size()==n)
    {
      for(int i=0; i<n; i++)cout << path[i] << " ";
      cout << endl;
    }
    else
    {
      for(int i=0; i<n; i++)if(g[s][i]>0 && visited[i]==false){
        allDFSUtil(g, i, visited, path);
      }
    }
  }

  void complementary_mst()
  {
    int g[100][100];

    for(int i=0; i<n; i++)for(int j=0; j<n; j++)g[i][j]=adj[i][j];

    priority_queue<edge, vector<edge>, func2> q;

    for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(adj[i][j]>0){
      edge ed; ed.weight=adj[i][j]; ed.src=i; ed.dest=j; q.push(ed);
    }

    while(!q.empty())
    {
      edge ed=q.top(); q.pop();

      g[ed.src][ed.dest]=0;
      g[ed.dest][ed.src]=0;
      vector<bool> visited(n, false);
      vector<int> path;
      allDFSUtil(g, 0, visited, path);

      if(path.size()!=n){
        g[ed.src][ed.dest]=ed.weight;
        g[ed.dest][ed.src]=ed.weight;
      }

    }

    cout << "Adjacency matrix of resultant mst graph is:" << endl;

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++)cout << g[i][j] << " ";
      cout << endl;
    }
  }

};

int main()
{
  Graph g(6);
    g.addEdge(0, 1, 6);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 3);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 4, 7);
    g.addEdge(2, 4, 8);
    g.addEdge(1, 5, 5);
    g.addEdge(3, 5, 2);
    g.addEdge(3, 1, 2);

    g.complementary_mst();

    return 0;
}

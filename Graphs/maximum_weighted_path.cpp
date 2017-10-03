#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
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
  void addEdge(int v, int w, int wt)
  {
    this->adj[v][w]=wt;
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

    for(int i=0; i<n; i++)if(adj[s][i]>0 && visited[i]==false)DFSUtil(i, visited);
  }

  void DFS(int s)
  {
    bool *visited=new bool[n];
    memset(visited, false, sizeof(visited[0])*n);

    DFSUtil(s, visited);
    cout << endl;
  }

  void pathsUtil(int s, vector<bool> visited, vector<int> path, int sz, int &maxsz)
  {
    visited[s]=true;
    path.push_back(s);

    for(int i=0; i<n; i++)
    {
      if(adj[s][i]>0 && visited[i]==false)
      {
        sz+=adj[s][i];
        if(maxsz<sz)maxsz=sz;

        pathsUtil(i, visited, path, sz, maxsz);

        sz-=adj[s][i];
      }
    }
  }

  int paths()
  {
    vector<bool> visited;
    for(int i=0; i<n; i++)visited.push_back(false);
    vector<int> path;
    int sz=0, maxsz=0;
    for(int i=0; i<n; i++)pathsUtil(i, visited, path, sz, maxsz);

    return maxsz;
  }
};

int main()
{
  Graph g(7);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 6);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 4, 9);
    g.addEdge(4, 5, 15);
    g.addEdge(4, 6, 17);

    g.DFS(0);
    cout << g.paths();

    return 0;
}

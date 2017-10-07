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
  void addEdge(int v, int w)
  {
    this->adj[v][w]=1;
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

  int indegree(int s)
  {
    int l=0;
    for(int i=0; i<n; i++)if(adj[i][s]>0)l++;
    return l;
  }

  int outdegree(int s)
  {
    int l=0;
    for(int i=0; i<n; i++)if(adj[s][i]>0)l++;
    return l;
  }

  void topological()
  {
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> inde;
    for(int i=0; i<n; i++)inde.push_back(indegree(i));
    for(int i=0; i<n; i++)if(inde[i]==0 && visited[i]==false){q.push(i); visited[i]=true;}

    while(!q.empty())
    {
      int t=q.front(); q.pop();
      cout << t << " ";
      for(int i=0; i<n; i++)if(inde[i]>=0)inde[i]--;

      for(int i=0; i<n; i++)if(inde[i]==0 && visited[i]==false){q.push(i); visited[i]=true;}
    }
  }
};

int main()
{
  Graph g(8);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 6);
    g.addEdge(3, 5);
    g.addEdge(5, 7);
    g.addEdge(6, 7);

    g.topological();

    return 0;
}

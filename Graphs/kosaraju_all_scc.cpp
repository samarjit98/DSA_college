#include <iostream>
#include <vector>
#include <stack>
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

  void DFS_store(int src, vector<bool> &visited, stack<int> &s)
  {
    visited[src]=true;

    for(int i=0; i<n; i++)if(adj[src][i]==1 && visited[i]==false)DFS_store(i, visited, s);

    s.push(src);
  }

  void DFSUtil(int g[100][100], int s, vector<bool> &visited)
  {
    visited[s]=true;
    cout << s << " ";

    for(int i=0; i<n; i++)if(g[s][i]==1 && visited[i]==false)DFSUtil(g, i, visited);
  }

  void all_strongly()
  {
    vector<bool> visited(n, false);
    stack<int> s;

    for(int i=0; i<n; i++)if(!visited[i])DFS_store(i, visited, s);

    int g[100][100];

    for(int i=0; i<n; i++)for(int j=0; j<n; j++)g[i][j]=0;

    for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(adj[i][j]==1)g[j][i]=1;

    for(int i=0; i<n; i++)visited[i]=false;

    while(!s.empty()){
      int cur=s.top(); s.pop();

      if(!visited[cur]){
        DFSUtil(g, cur, visited);
        cout << endl;
      }
    }
  }
};

int main()
{

  Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(1, 5);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    g.addEdge(5, 2);
    g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(7, 5);
    g.addEdge(7, 9);
    g.addEdge(9, 8);
    g.addEdge(8, 7);

    g.all_strongly();

    return 0;
}

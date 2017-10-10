#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
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
    this->adj[w][v]=wt;
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

  void DFSUtil(int g[100][100],int s, bool visited[])
  {
    visited[s]=true;
    cout << s << " ";

    for(int i=0; i<n; i++)if(g[s][i]>0 && visited[i]==false)DFSUtil(g, i, visited);
  }

  void DFS( int g[100][100], int s)
  {
    bool *visited=new bool[n];
    memset(visited, false, sizeof(visited[0]));
    //int ct=0;
    DFSUtil(g, s, visited);
    cout << endl;
  }

  void mst()
  {
    set<int> a;
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(adj[i][j]>0)a.insert(adj[i][j]);
    set<int>::iterator it;

    int g[100][100];
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)g[i][j]=0;

    for(it=a.begin(); it!=a.end(); it++)
    {
      int ed=*it;
      for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(adj[i][j]==ed || adj[j][i]==ed)
      {
        vector<bool> visited1(n, false);
        vector<int> path1;
        allDFSUtil(g, i, visited1, path1);

        vector<bool> visited2(n, false);
        vector<int> path2;
        allDFSUtil(g, j, visited2, path2);

        sort(path1.begin(), path1.end());
        sort(path2.begin(), path2.end());
        if(path1!=path2){
          g[i][j]=ed;
          g[j][i]=ed;
        }
      }

      vector<bool> visited(n, false);
      vector<int> path;
      allDFSUtil(g, 1, visited, path);

      if(path.size()==n)break;
    }
    cout << endl;
    DFS(g, 3); cout << endl;
    DFS(g, 1); cout << endl;
    DFS(g, 5);
    cout << endl;

    for(int i=0; i<n; i++){for(int j=0; j<n; j++)cout << g[i][j] << " "; cout << endl;}
  }
};

int main()
{
  Graph g(7);
    g.addEdge(0, 1, 6);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 3);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 4, 7);
    g.addEdge(2, 4, 8);
    g.addEdge(1, 5, 5);
    g.addEdge(3, 5, 2);
    g.addEdge(3, 1, 2);

    g.mst();

    return 0;
}

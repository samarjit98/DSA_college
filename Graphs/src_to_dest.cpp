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

  void DFSUtil(int src, int dest, vector<bool> visited, vector<int> path, vector<int> &ret, bool &flag)
  {
    visited[src]=true;
    path.push_back(src);

    for(int i=0; i<n; i++){
      if(adj[src][i]==1 && i==dest){
        for(int j=0; j<path.size(); j++)ret.push_back(path[j]);
        ret.push_back(i);
        flag=true;
      }
      else if(adj[src][i]==1 && !visited[i])DFSUtil(i, dest, visited, path, ret, flag);
    }
  }

  void DFS(int src, int dest)
  {
    vector<bool> visited(n, false);
    vector<int> path;
    vector<int> ret;
    bool flag=false;
    DFSUtil(src, dest, visited, path, ret, flag);

    if(flag){
      cout << "Path exists!!" << endl;
      for(int i=0; i<ret.size(); i++){cout << ret[i] << " "; if(ret[i]==dest)cout << endl;}
      cout << endl;
    }
    else cout << "Path does not exist!!\n\n";
  }
};

int main()
{
  Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 5);
    g.addEdge(5, 4);

    g.DFS(0, 5);
    g.DFS(5, 1);
    g.DFS(2, 4);
    g.DFS(4, 0);

    return 0;
}

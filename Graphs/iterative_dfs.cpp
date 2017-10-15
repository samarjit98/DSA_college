#include <iostream>
#include <stack>
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

  void DFS(int src)
  {
    stack<int> s;
    vector<bool> visited(n, false);

    s.push(src);
    visited[src]=true;

    while(!s.empty()){
      int cur=s.top(); s.pop();
      cout << cur << " ";

      for(int i=0; i<n; i++)if(adj[cur][i]==1 && visited[i]==false){
        visited[i]=true;
        s.push(i);
      }
    }
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

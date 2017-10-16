#include <iostream>
#include <vector>
#include <limits.h>
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
  void addEdge(int v, int w, int k)
  {
    this->adj[v][w]=k; this->adj[w][v]=k;
  }

  void prims()
  {
    vector<bool> visited(n, false);
    vector<int> parent(n);
    vector<int> key(n, INT_MAX);

    key[0]=0;
    parent[0]=-1;

    for(int j=0; j<n-1; j++){

      int pos=0, minkey=INT_MAX;

      for(int i=0; i<n; i++){
        if(key[i]<minkey && !visited[i]){
          pos=i; minkey=key[i];
        }
      }

      visited[pos]=true;

      for(int i=0; i<n; i++){
        if(adj[pos][i]>0 && !visited[i] && key[i]>adj[pos][i]){
          key[i]=adj[pos][i]; parent[i]=pos;
        }
      }
    }

    int g[100][100];

    for(int i=0; i<n; i++){
      if(parent[i]!=-1){
        g[i][parent[i]]=adj[i][parent[i]];
        g[parent[i]][i]=adj[parent[i]][i];
      }
    }

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

    g.prims();

    return 0;
}

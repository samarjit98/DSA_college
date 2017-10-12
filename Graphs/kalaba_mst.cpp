#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
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
  void addEdge(int v, int w, int k)
  {
    adj[v][w]=k;
    adj[w][v]=k;
  }

  void cyclesUtil(int s, int g[100][100], vector<bool> visited, vector<int> path, vector<int> &ret)
  {
    visited[s]=true;
    path.push_back(s);

    for(int i=0; i<n; i++)
    {
      if(g[s][i]>0 && visited[i]==true && i==path[0] && path.size()!=2)
      {
        for(int j=0; j<path.size(); j++)ret.push_back(path[j]);
        ret.push_back(i);
      }
      else if(g[s][i]>0 && visited[i]==false)cyclesUtil(i, g, visited, path, ret);
    }
  }

  void kalaba()
  {
    int g[100][100];

    for(int i=0; i<n; i++)for(int j=0; j<n; j++)g[i][j]=0;

    for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(adj[i][j]>0){
      g[i][j]=adj[i][j]; g[j][i]=adj[i][j];

      vector<bool> visited(n, false);
      vector<int> path;
      vector<int> ret;
      cyclesUtil(i, g, visited, path, ret);
      
      if(ret.size()>0){
        int maxsrc=ret[0], maxdest=ret[1], maxw=g[ret[0]][ret[1]];

        for(int i=0; i<ret.size()-1; i++)
        {
          if(g[ret[i]][ret[i+1]]>maxw){
            maxsrc=ret[i]; maxdest=ret[i+1];
          }
        }
        if(g[ret[ret.size()-1]][ret[0]]>maxw){maxsrc=ret[ret.size()-1]; maxdest=ret[0];}

        g[maxsrc][maxdest]=0;
        g[maxdest][maxsrc]=0;
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

    g.kalaba();

    Graph a(3);
    a.addEdge(0, 1, 2);
    a.addEdge(0, 2, 3);
    a.addEdge(1, 2, 4);
    a.kalaba();

    return 0;
}

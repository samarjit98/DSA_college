#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


struct edge{
  int weight;
  int src;
  int dest;
};

bool func(edge e1, edge e2){
  return e1.weight<e2.weight;
}

class disjset
{
  int *s;

public:
  disjset(int n);
  int root(int n);
  void connect(int i, int j);
  bool find(int i, int j);
};

disjset::disjset(int n)
{
  s=new int[n];
  for(int i=0; i<n; i++)s[i]=i;
}

int disjset::root(int n)
{
  while(n!=s[n])n=s[n];
  return n;
}

void disjset::connect(int i, int j)
{
  int iroot=root(i);
  int jroot=root(j);
  s[iroot]=jroot;
  /*
  The same thing can also be written as
    s[jroot]=s[iroot];
  */
}

bool disjset::find(int i, int j)
{
  return (root(i)==root(j));
}


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

  void kruskals()
  {
    int g[100][100];

    for(int i=0; i<n; i++)for(int j=0; j<n; j++)g[i][j]=0;

    disjset s(n);
    int e=0;
    vector<edge> v;

    for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(adj[i][j]>0){
      edge ed; ed.weight=adj[i][j]; ed.src=i; ed.dest=j; v.push_back(ed);
    }
    sort(v.begin(), v.end(), func);
    int pos=0;

    while(e<n-1)
    {
      if(pos>=v.size())break;
      
      edge ed=v[pos]; pos++;

      if(!s.find(ed.src, ed.dest))
      {
        s.connect(ed.src, ed.dest);
        g[ed.src][ed.dest]=ed.weight;
        g[ed.dest][ed.src]=ed.weight;
        e++;
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

    g.kruskals();

    return 0;
}

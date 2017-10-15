#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

struct node{
  int v; int wt;
};

class Graph{
  int n;
  list<node> *adj;

public:
  Graph(int v)
  {
    n=v;
    adj=new list<node>[v];
  }
  void addEdge(int v, int w, int wt)
  {
    node e; e.v=w; e.wt=wt;
    adj[v].push_back(e);
  }
  void topologicUTIL(int cur, vector<bool> &visited, stack<int> &s)
  {
    visited[cur]=true;
    list<node>::iterator i;
    for(i=adj[cur].begin(); i!=adj[cur].end(); i++){
      node e=*i;
      if(!visited[e.v]){
        topologicUTIL(e.v, visited, s);
      }
    }
    s.push(cur);
  }
  void topological()
  {
    vector<bool> visited(n, false);
    stack<int> s;
    for(int i=0; i<n; i++){
      if(!visited[i]){
        topologicUTIL(i, visited, s);
      }
    }
    while(!s.empty()){
      cout << s.top() << " "; s.pop();
    }
  }
  void longestpath(int src)
  {
    stack<int> s;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
      if(!visited[i]){
        topologicUTIL(i, visited, s);
      }
    }

    vector<int> dist(n, INT_MIN);
    dist[src]=0;
    while(!s.empty()){
      int curr=s.top(); s.pop();

      list<node>::iterator i;

      for(i=adj[curr].begin(); i!=adj[curr].end(); i++){
        node e=*i;
        if(dist[e.v]<dist[curr]+e.wt){
          dist[e.v]=dist[curr]+e.wt;
        }
      }
    }

    for(int i=0; i<n; i++)cout << i << " -> " << dist[i] << endl;
  }
};

int main()
{
  Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.longestpath(1);

  return 0;
}

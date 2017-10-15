#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

class Graph{
  int n;
  list<int> *adj;

public:
  Graph(int v)
  {
    n=v;
    adj=new list<int>[v];
  }
  void addEdge(int v, int w)
  {
    adj[v].push_back(w);
  }
  void topologicUTIL(int cur, vector<int> &visited, stack<int> &s)
  {
    visited[cur]=true;
    list<int>::iterator i;
    for(i=adj[cur].begin(); i!=adj[cur].end(); i++){
      if(!visited[*i]){
        topologicUTIL(*i, visited, s);
      }
    }
    s.push(cur);
  }
  void topological()
  {
    vector<int> visited(n, false);
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

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
  int n;
  vector<int> *adj;

public:
  Graph(int v)
  {
    n=v;
    adj=new vector<int>[v];
  }
  void addEdge(int v, int w)
  {
    adj[v].push_back(w);
    adj[w].push_back(v);
  }
  bool BFS(int v)
  {
    vector<int> visited(n, false);
    vector<int> level(n);
    queue<int> q;

    visited[v]=true;
    level[v]=0;
    q.push(v);

    while(!q.empty()){
      int cur=q.front(); q.pop();

      for(int i=0; i<adj[cur].size(); i++){
        if(!visited[adj[cur][i]]){
          visited[adj[cur][i]]=true;
          level[adj[cur][i]]=level[cur]+1;
          q.push(adj[cur][i]);
        }
        else if(level[adj[cur][i]]==level[cur])return false;
      }
    }
    return true;
  }
};

int main()
{
  Graph g(3);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 0);

  if(g.BFS(0))cout << "Bipartite" << endl;
  else cout << "Not Bipartite" << endl;

  return 0;
}

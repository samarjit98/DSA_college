#include <iostream>
#include <list>
#include <queue>
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
    adj[w].push_back(v);
  }
  void BFS(int src)
  {
    queue<int> q;
    list<int>::iterator i;
    vector<int> visited(n, false);
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
      int curr=q.front(); q.pop();
      cout << curr << " ";
      for(i=adj[curr].begin(); i!=adj[curr].end(); i++){
        if(visited[*i]==false){
          q.push(*i);
          visited[*i]=true;
        }
      }
    }
    cout << endl;
  }
};

int main()
{
  Graph q(6);
  q.addEdge(0, 1);
  q.addEdge(1, 2);
  q.addEdge(2, 3);
  q.addEdge(3, 4);
  q.addEdge(4, 5);
  q.addEdge(5, 0);
  q.addEdge(0, 3);
  q.BFS(0);
  return 0;
}

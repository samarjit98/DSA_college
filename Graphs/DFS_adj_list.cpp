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
  void DFSUtil(int s, vector<int> &visited)
  {
    cout << s << " "; visited[s]=true;

    list<int>::iterator i;
    for(i=adj[s].begin(); i!=adj[s].end(); i++){
      if(!visited[*i]){
        DFSUtil(*i, visited);
      }
    }
  }
  void DFS(int src)
  {
    vector<int> visited(n, false);

    DFSUtil(src, visited); cout << endl;
  }
};

int main()
{
  Graph q(6);
  q.addEdge(0, 1);
  q.addEdge(1, 2);
  q.addEdge(1, 4);
  q.addEdge(3, 4);
  q.addEdge(4, 5);
  q.addEdge(5, 0);

  q.DFS(0);
  return 0;
}

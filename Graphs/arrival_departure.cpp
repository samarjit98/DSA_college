#include <iostream>
#include <vector>
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
  }
  void DFS(int s, vector<int> &arrival, vector<int> &departure, vector<bool> &visited, int &time)
  {
    visited[s]=true;
    arrival[s]=time++;

    for(int i=0; i<adj[s].size(); i++){
      if(!visited[adj[s][i]])DFS(adj[s][i], arrival, departure, visited, time);
    }

    departure[s]=time++;
  }
  void DFS_time()
  {
    vector<bool> visited(n, false);
    vector<int> arrival(n);
    vector<int> departure(n);
    int time=0;

    for(int i=0; i<n; i++){
      if(!visited[i]){
        DFS(i, arrival, departure, visited, time);
      }
    }

    for(int i=0; i<n; i++){
      cout << "( " << i << ", " << arrival[i] << ", " << departure[i] << " )" << endl;
    }
  }
};

int main()
{
  Graph g(8);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 1);
  g.addEdge(2, 4);
  g.addEdge(4, 5);
  g.addEdge(3, 5);
  g.addEdge(6, 7);

  g.DFS_time();

  return 0;
}

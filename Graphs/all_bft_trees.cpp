#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
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
    this->adj[w][v]=1;
  }
  void BFS(int s)
  {
    bool visited[n];
    memset(visited, false, sizeof(visited[0]));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
      int curr=q.front(); q.pop();
      cout << curr << " ";
      for(int i=0; i<n; i++)
      {
        if(adj[curr][i]==1 && visited[i]==false){q.push(i); visited[i]=true;}
      }
    }
  }

  void allDFSUtil(int s, vector<bool> visited, vector<int> path)
  {
    visited[s]=true;
    path.push_back(s);

    if(path.size()==n)
    {
      for(int i=0; i<path.size(); i++)cout << path[i] << " ";
      cout << endl;
    }
    else
    {
      for(int i=0; i<n; i++)if(adj[s][i]>0 && visited[i]==false){
        allDFSUtil(i, visited, path);
      }
    }
  }

  void allDFS(int s)
  {
    vector<bool> visited(n, false);
    vector<int> path;
    /*
    There is a very fundamental and minute difference between using a vector instead of an array.
    Hint: It lies in the passing mechanisms :P xD!!
    This small difference makes a normal DFS, an extremely awesome AllDFS!
    */
    allDFSUtil(s, visited, path);
  }
};

int main()
{
  Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);

    g.BFS(2);
    cout << endl << endl;
    cout << "All DFS" << endl;
    g.allDFS(0);

    return 0;
}

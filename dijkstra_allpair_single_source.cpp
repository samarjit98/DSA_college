#include <bits/stdc++.h>
using namespace std;


struct spec{
  int vt; int dist; int prev;
};

struct func2{
  bool operator()(spec &s1, spec &s2)
  {
    return s1.dist<s2.dist;
  }
};

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
  void addEdge(int v, int w, int wt)
  {
    this->adj[v][w]=wt;
  }

  void DFSUtil(int s, bool visited[])
  {
    visited[s]=true;
    cout << s << " ";

    for(int i=0; i<n; i++)if(adj[s][i]>0 && visited[i]==false)DFSUtil(i, visited);
  }

  void DFS(int s)
  {
    bool *visited=new bool[n];
    memset(visited, false, sizeof(visited[0])*n);

    DFSUtil(s, visited);
    cout << endl;
  }

  int djikstra(int v, int w)
  {
    vector<spec> specs;

    for(int i=0; i<n; i++){
      spec tmp; tmp.vt=i; tmp.dist=INT_MAX; tmp.prev=-1; specs.push_back(tmp);
    }
    /*
    vector<bool> visited;
    for(int i=0; i<n; i++)visited.push_back(false);
    */
    specs[v].dist=0;
    priority_queue<spec, vector<spec>, func2> q;
    q.push(specs[v]);

    while(!q.empty()){
      spec curr=q.top(); q.pop();
      //visited[curr.vt]=true;
      for(int i=0; i<n; i++)
      {
        if(adj[curr.vt][i]>0 /*&& visited[i]==false*/){
          if(specs[i].dist>curr.dist+adj[curr.vt][i]){
            specs[i].dist=curr.dist+adj[curr.vt][i]; specs[i].prev=curr.vt;
            q.push(specs[i]);
          }
        }
      }
    }

    int tmp=w;

    cout << "Path length: " << specs[w].dist << endl;
    cout << "Paths: ";
    while(tmp!=-1)
    {
      cout << specs[tmp].vt << " ";
      tmp=specs[tmp].prev;
    }
    cout << endl << endl;

    cout << "----------------------------------------------------------" << endl;
    cout << "All pair shortest path:\n\n" << endl;

    for(int i=1; i<n; i++)
    {
      cout << v << " " << i << endl;

      tmp=i;

      cout << "Path Length: " << specs[i].dist << endl;

      cout << "Path: ";

      while(tmp!=-1){
        cout << specs[tmp].vt << " ";
        tmp=specs[tmp].prev;
      }
      cout << endl << endl;
    }
  }

};

int main()
{
  Graph g(8);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 5, 10);
    g.addEdge(1, 4, 1);
    g.addEdge(4, 5, 2);
    g.addEdge(4, 7, 4);
    g.addEdge(5, 7, 6);
    g.addEdge(3, 1, 4);
    g.addEdge(3, 6, 5);
    g.addEdge(4, 3, 2);
    g.addEdge(4, 6, 8);
    g.addEdge(7, 6, 1);

    g.DFS(1);
    cout << endl;
    g.djikstra(1, 6);
/*
    cout << endl << endl;
  Graph a(4);

  g.addEdge(1, 2, 7);
  g.addEdge(1, 3, 1);
  g.addEdge(3, 2, 1);

  g.DFS(1);
  cout << endl;
  g.djikstra(1, 2);
*/
    return 0;
}

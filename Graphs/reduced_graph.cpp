#include <iostream>
#include <vector>
#include <stack>
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
  void addEdge(int v, int w)
  {
    this->adj[v][w]=1;
  }

  void DFS_store(int src, vector<bool> &visited, stack<int> &s)
  {
    visited[src]=true;

    for(int i=0; i<n; i++)if(adj[src][i]==1 && visited[i]==false)DFS_store(i, visited, s);

    s.push(src);
  }

  void DFSUtil(int g[100][100], int s, vector<bool> &visited, vector<int> &a)
  {
    visited[s]=true;
    a.push_back(s);
    cout << s << " ";

    for(int i=0; i<n; i++)if(g[s][i]==1 && visited[i]==false)DFSUtil(g, i, visited, a);
  }

  void all_strongly()
  {
    vector<bool> visited(n, false);
    stack<int> s;

    for(int i=0; i<n; i++)if(!visited[i])DFS_store(i, visited, s);

    int g[100][100];

    for(int i=0; i<n; i++)for(int j=0; j<n; j++)g[i][j]=0;

    for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(adj[i][j]==1)g[j][i]=1;

    fill(visited.begin(), visited.end(), false);

    vector<vector<int> > scc;

    while(!s.empty()){
      int cur=s.top(); s.pop();
      vector<int> a;
      if(!visited[cur]){
        DFSUtil(g, cur, visited, a);
        scc.push_back(a); cout << endl;
      }
    }
    cout << endl << endl;
    int max=0, pos=0;
    for(int i=0; i<scc.size(); i++){
      if(scc[i].size()>max){
        max=scc[i].size(); pos=i;
      }
    }

    int g2[100][100];
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)g2[i][j]=0;

/*
    for(int i=0; i<scc[pos].size(); i++){
      for(int j=0; j<scc[pos].size(); j++){
        if(adj[scc[pos][i]][scc[pos][j]]==1){
          g2[scc[pos][i]][scc[pos][j]]=1; cout << scc[pos][i] << " " << scc[pos][j] << endl;
        }
        else if(adj[scc[pos][j]][scc[pos][i]]==1){
          g2[scc[pos][j]][scc[pos][i]]=1; cout << scc[pos][j] << " " << scc[pos][i] << endl;
        }
      }
    }
    cout << endl;
    for(int i=0; i<scc.size(); i++){
      if(i!=pos){
        int w=scc[i][0];
        for(int j=0; j<scc[i].size(); i++){
          for(int k=0; k<scc[pos].size(); k++){
            if(adj[scc[i][j]][scc[pos][k]]==1){
              g2[w][scc[pos][k]]=1; cout << w << " " << scc[pos][k] << endl;
            }
            else if(adj[scc[pos][k]][scc[i][j]]==1){
              g2[scc[pos][k]][w]=1; cout << scc[pos][k] << " " << w << endl;
            }
          }
          cout << endl;
        }
      }
    }
*/
    for(int i=0; i<scc.size(); i++){
      for(int j=0; j<scc.size(); j++){
        if(i!=j){
          int tmp1=scc[i][0], tmp2=scc[j][0];
          for(int k=0; k<scc[i].size(); k++){
            for(int l=0; l<scc[j].size(); l++){
              if(adj[scc[i][k]][scc[j][l]]==1){
                g2[tmp1][tmp2]=1; cout << tmp1 << " " << tmp2 << " - " << scc[i][k] << " " << scc[j][l] << endl;
              }
              else if(adj[scc[j][l]][scc[i][k]]==1){
                g2[tmp2][tmp1]=1; cout << tmp2 << " " << tmp1 << " - " << scc[j][l] << " " << scc[i][k] << endl;
              }
            }
          }
        }
      }
    }
    cout << "Graph edges:" << endl;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++)cout << g2[i][j] << " ";
      cout << endl;
    }

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++)if(g2[i][j]==1)cout << i << " --> " << j << endl;
    }
  }
};

int main()
{

  Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(1, 5);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    g.addEdge(5, 2);
    g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(7, 5);
    g.addEdge(7, 9);
    g.addEdge(9, 8);
    g.addEdge(8, 7);

    g.all_strongly();

    return 0;
}

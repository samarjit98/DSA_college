#include <iostream>
#include <queue>
#include <cstring>
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

  int degree(int s)
  {
    int l=0;
    for(int i=0; i<n; i++)if(adj[s][i]==1)l++;

    return l;
  }

  void euler(int vt, int g[100][100], vector<int> &deg, vector<int> &path)
  {
    if(path.size()>0 && path[0]==vt){path.push_back(vt); deg[vt]--;}
    else
    {
      path.push_back(vt); deg[vt]--;
      for(int i=0; i<n; i++)if(g[vt][i]==1){
        g[vt][i]=0;
        g[i][vt]=0;
        euler(i, g, deg, path);
        break;
      }
    }
  }

  void eulerUTIL()
  {
    vector<int> deg;
    for(int i=0; i<n; i++)deg.push_back(degree(i));

    vector<int> path;
    vector<int> ans;
    int g[100][100];
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)g[i][j]=adj[i][j];

    int flag=0; int vt; int pos=0;

    for(int i=0; i<n; i++)if(deg[i]>0){flag=1; vt=i; break;}

    while(flag!=0)
    {
      euler(vt, g, deg, path);

      if(ans.size()==0)
      {
        for(int i=0; i<path.size(); i++)ans.push_back(path[i]);
      }
      else
      {
        for(int i=0; i<path.size(); i++)ans.insert(ans.begin()+pos+i, 1, path[i]);
      }
      path.clear();
      flag=0;

      for(int i=0; i<n; i++)if(deg[ans[i]]>0){flag=1; vt=ans[i]; pos=i; break;}
    }
    for(int i=0; i<ans.size()-1; i++)if(ans[i]==ans[i+1])ans[i]=-1;

    cout << "Euler path:" << endl;
    for(int i=0; i<ans.size(); i++)if(ans[i]!=-1)cout << ans[i] << " ";
    cout << endl;
  }
};

int main()
{
  Graph g(13);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 8);
    g.addEdge(8, 9);
    g.addEdge(3, 6);
    g.addEdge(6, 9);
    g.addEdge(3, 9);
    g.addEdge(3, 7);
    g.addEdge(7, 9);
    g.addEdge(4, 7);
    g.addEdge(4, 10);
    g.addEdge(7, 10);
    g.addEdge(9, 10);
    g.addEdge(9, 12);
    g.addEdge(10, 12);
    g.addEdge(4, 5);
    g.addEdge(5, 10);
    g.addEdge(4, 11);
    g.addEdge(10, 11);

    cout << endl;

    g.eulerUTIL();

    return 0;
}

#include <iostream>
using namespace std;

class disjset
{
  int *s;

public:
  disjset(int n);
  int root(int n);
  void connect(int i, int j);
  bool find(int i, int j);
};

disjset::disjset(int n)
{
  s=new int[n];
  for(int i=0; i<n; i++)s[i]=i;
}

int disjset::root(int n)
{
  while(n!=s[n])n=s[n];
  return n;
}

void disjset::connect(int i, int j)
{
  int iroot=root(i);
  int jroot=root(j);
  s[iroot]=jroot;
  /*
  The same thing can also be written as
    s[jroot]=s[iroot];
  */
}

bool disjset::find(int i, int j)
{
  return (root(i)==root(j));
}

int main()
{
  int n, m;
  cin >> n;
  disjset d(n);
  cin >> m;
  while(m--)
  {
    int i, j;
    cin >> i >> j;
    d.connect(i, j);
  }
  cout << "Find:" << endl;
  int p, q;
  cin >> p >> q;
  if(d.find(p, q))cout << "Same set";
  else cout << "Different set";
  cout << endl;
  return 0;
}

/*
Use C++11 or above for unordered_set or hash table.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool prod_find(vector<int> a, int n)
{
  unordered_set<int> s;

  for(int i=0; i<a.size(); i++)
  {
    if(a[i]==0 && n==0)return true;

    if(n%a[i]==0 && (s.find(n/a[i])!=s.end()))return true;
    else s.insert(a[i]);
  }
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a;
  for(int i=0; i<n; i++)
  {
    int t; cin >> t; a.push_back(t);
  }
  if(prod_find(a, m))cout << "Yes\n";
  else cout << "No\n";

  return 0;
}

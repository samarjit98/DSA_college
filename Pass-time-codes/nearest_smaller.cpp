#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void nearest_small(vector<int> a)
{
  stack<int> s;
  for(int i=0; i<a.size(); i++)
  {
    if(i==0){s.push(a[i]); cout << "NIL ";}
    else
    {
      while(s.top()>=a[i] && !s.empty())s.pop();

      if(s.empty())cout << "NIL ";
      else cout << s.top() << " ";
      s.push(a[i]);
    }
  }
  cout << endl;
}

int main()
{
  vector<int> a;
  int tmp, n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> tmp; a.push_back(tmp);
  }
  nearest_small(a);
  return 0;
}

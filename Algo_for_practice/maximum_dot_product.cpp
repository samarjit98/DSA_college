#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int maximumDotProduct(vector<int> a, vector<int> b)
{
  int dp[a.size()+1][b.size()+1];
  memset(dp, 0, sizeof(dp));
  for(int i=1; i<=a.size(); i++)
    for(int j=i; j<=b.size(); j++)
      dp[i][j]=max(dp[i-1][j-1]+a[i-1]*b[j-1], dp[i][j-1]);

  return dp[a.size()][b.size()];
}

int main()
{
  int n, m, tmp;
  vector<int> a, b;
  cin >> n >> m;
  while(n--)
  {
    cin >> tmp; a.push_back(tmp);
  }
  while(m--)
  {
    cin >> tmp; b.push_back(tmp);
  }
  cout << maximumDotProduct(b, a);
  return 0;
}

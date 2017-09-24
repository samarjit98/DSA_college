#include <bits/stdc++.h>
using namespace std;

#define N 1000

int dp[N];

int rec(int i, int a[N])
{
  if(i<0)return 0;
  else if(dp[i]!=INT_MIN)return dp[i];
  else{dp[i]=max(rec(i-1, a)+a[i], a[i]); return dp[i];}
}

int max_sum(int a[N], int n)
{
  int maxi=INT_MIN;
  for(int i=0; i<n; i++)
  {
    maxi=max(maxi, rec(i, a));
  }
  return maxi;
}

int main()
{
  for(int i=0; i<N; i++)dp[i]=INT_MIN;
  int n;
  cin >> n;
  int a[N];
  for(int i=0; i<n; i++)cin >> a[i];
  for(int i=0; i<=n; i++)cout << max_sum(a, i) << " ";
  return 0;
}

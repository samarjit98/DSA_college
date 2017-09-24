#include <iostream>
using namespace std;

const long long mod=1000000007;

void mul(long long a[2][2], long long b[2][2])
{
  long long t1[2][2], t2[2][2];
  t1[0][0]=a[0][0]; t1[0][1]=a[0][1]; t1[1][0]=a[1][0]; t1[1][1]=a[1][1];
  t2[0][0]=b[0][0]; t2[0][1]=b[0][1]; t2[1][0]=b[1][0]; t2[1][1]=b[1][1];
  a[0][0]=(((t1[0][0]%mod)*(t2[0][0]%mod))%mod+((t1[0][1]%mod)*(t2[1][0]%mod))%mod)%mod;
  a[0][1]=(((t1[0][0]%mod)*(t2[0][1]%mod))%mod+((t1[0][1]%mod)*(t2[1][1]%mod))%mod)%mod;
  a[1][0]=(((t1[1][0]%mod)*(t2[0][0]%mod))%mod+((t1[1][1]%mod)*(t2[1][0]%mod))%mod)%mod;
  a[1][1]=(((t1[1][0]%mod)*(t2[0][1]%mod))%mod+((t1[1][1]%mod)*(t2[1][1]%mod))%mod)%mod;
}

void pow(long long f[2][2], long long n)
{
  if(n==0||n==1)return;
  else if(n%2==0)
  {
    pow(f, n/2);
    mul(f,f);
  }
  else
  {
    long long t[2][2];
    t[0][0]=f[0][0]; t[0][1]=f[0][1]; t[1][0]=f[1][0]; t[1][1]=f[1][1];
    pow(f, n/2);
    mul(f, f);
    mul(f, t);
  }
}

long long fib(long long n)
{
  long long f[2][2]={{1,1},{1,0}};
  pow(f,n);
  return f[0][1];
}

int main()
{
  long long n;
  cin >> n;
  cout << fib(n);
  return 0;
}

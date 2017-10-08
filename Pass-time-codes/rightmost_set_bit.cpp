#include <iostream>
#include <math.h>
using namespace std;

int posi(int n)
{
  return log2(n&-n)+1;
}

int main()
{
  int n; cin >> n;
  cout << posi(n) << endl;
  return 0;
}

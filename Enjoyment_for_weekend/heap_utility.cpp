#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Heap
{
  vector<int> arr;

public:
  Heap()
  {
    arr.push_back(INT_MIN);
  }

  bool checkheap()
  {
    for(int i=arr.size()-1; i>=1; i--)
      if(arr[i/2]>arr[i])return false;

    return true;
  }

  void heapify(int k)
  {
    arr.push_back(k);
    int s=arr.size()-1;
    while(s!=1)
    {
      if(arr[s/2]>arr[s])swap(arr[s/2], arr[s]);
      s/=2;
    }
  }

  void print_heap()
  {
    int k=1, j=0;

    for(int i=1; i<arr.size(); i++)
    {
      cout << arr[i] << " ";
      j++;

      if(j==k)
      {
        cout << endl; j=0; k*=2;
      }
    }
  }

  void heap_sort()
  {
    int s=arr.size()-1;
    while(s!=1)
    {
      cout << arr[1] << " ";
      arr[1]=arr[s]; int i=1;
      while(arr[i]>arr[2*i] && arr[i]>arr[2*i+1])
      {
        if(arr[2*i]<arr[2*i+1])
        {
          swap(arr[i], arr[2*i]); i*=2;
        }
        else
        {
          swap(arr[i], arr[2*i+1]); i=2*i+1;
        }

        if(i>s)break;
      }
      s--;
    }
  }
};

int main()
{
  Heap h;

  int n, a; cin >> n;

  while(n--)
  {
    cin >> a; h.heapify(a);
  }

  if(h.checkheap())h.print_heap();
  else cout << "NOT HEAP";

  h.heap_sort();
  return 0;
}

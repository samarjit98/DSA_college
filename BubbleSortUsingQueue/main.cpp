#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &a)
{
    queue<int> q;
    for(int i=0; i<a.size(); i++)q.push(a[i]);

    int n=q.size();

    for(int i=0; i<n; i++)
    {
        int x=q.front();
        q.pop();
        for(int j=0; j<n-1; j++)
        {
            int y=q.front();
            q.pop();
            if(x>y)
            {
                q.push(y);
            }
            else
            {
                q.push(x);
                x=y;
            }
        }
        q.push(x);
    }

    a.clear();

    for(int i=0; i<n; i++)
    {
        int tmp=q.front();
        q.pop();
        a.push_back(tmp);
    }
}

int main()
{
    int tmp, n;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    BubbleSort(a);
    for(int i=0; i<a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

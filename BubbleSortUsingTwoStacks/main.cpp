#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void BubbleSort(vector<int> &a)
{
    stack<int> p, q;

    for(int i=0; i<a.size(); i++)p.push(a[i]);

    int n=a.size();

    for(int i=0; i<n; i++)
    {
        while(!p.empty())
        {
            int tmp=p.top(); p.pop();
            q.push(tmp);
        }
        int x=q.top(); q.pop();
        for(int j=0; j<n-1; j++)
        {
            int y=q.top(); q.pop();
            if(x<y)
            {
                while(!q.empty())
                {
                    int tmp=q.top(); q.pop();
                    p.push(tmp);
                }
                p.push(x);
                while(!p.empty())
                {
                    int tmp=p.top(); p.pop();
                    q.push(tmp);
                }
                x=y;
            }
            else
            {
                while(!q.empty())
                {
                    int tmp=q.top(); q.pop();
                    p.push(tmp);
                }
                p.push(y);
                while(!p.empty())
                {
                    int tmp=p.top(); p.pop();
                    q.push(tmp);
                }
            }
        }

        q.push(x);

        while(!q.empty())
        {
            int tmp=q.top(); q.pop();
            p.push(tmp);
        }
    }

    a.clear();

    while(!p.empty())
    {
        int tmp=p.top(); p.pop();
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
        cin >> tmp; a.push_back(tmp);
    }

    BubbleSort(a);

    for(int i=0; i<a.size(); i++)cout << a[i] << " ";

    return 0;
}

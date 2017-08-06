#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	scanf("%d \n", &t);
	while(t--)
	{
	    multimap<long long, vector<long long> > a;
	    multimap<long long, vector<long long> >::reverse_iterator it;
	    long long tmp1, tmp2, tmp3, n, d;
	    scanf("%lli %lli", &n, &d);
	    for(long long i=0; i<n; i++)
	    {
	        scanf("%lli %lli %lli", &tmp1, &tmp2, &tmp3);
	        vector<long long> tmp;
	        tmp.push_back(tmp1);
	        tmp.push_back(tmp2);
	        a.insert(pair<long long, vector<long long> > (tmp3, tmp));
	    }
	    long long sad;
	    long long ans=0;
	    long long arr[d];
	    for(long long i=0; i<d; i++)arr[i]=0;
	    for(it=a.rbegin(); it!=a.rend(); it++)
	    {
	        vector<long long> dt;
	        sad=it->first; dt=it->second;
	        
	        for(long long i=dt[0]-1; i<d; i++)
	        {
	            if(arr[i]==0)
	            {
	                arr[i]=1;
	                dt[1]--;
	            }
	            
	            if(dt[1]==0)break;
	        }
	        
	        ans = ans + dt[1]*sad;
	    }
	    printf("%lli\n", ans);
	}
	return 0;
}

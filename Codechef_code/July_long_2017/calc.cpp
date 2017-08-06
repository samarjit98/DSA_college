    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	int t;
    	scanf("%d \n", &t);
    	while(t--)
    	{
    	    long long n, b, tmp, ans;
    	    scanf("%lli %lli", &n, &b);
    	    tmp = n/2;
    	    if(tmp%b==0 || (n-tmp)%b==0)ans=(n*n)/(4*b);
    	    else
    	    {
    	        long long tmp1 = (tmp/b)*b;
    	        long long tmp2 = (tmp/b)*b + b;
    	        long long ans1 = (tmp1*(n-tmp1))/b;
    	        long long ans2 = (tmp2*(n-tmp2))/b;
    	        
    	        long long ans11 = max(ans1, ans2);
    	        
    	        tmp = n-tmp;
    	        tmp1 = (tmp/b)*b;
    	        tmp2 = (tmp/b)*b + b;
    	        ans1 = (tmp1*(n-tmp1))/b;
    	        ans2 = (tmp2*(n-tmp2))/b;
    	        
    	        long long ans12 = max(ans1, ans2);
    	        
    	        ans = max(ans11, ans12);
    	    }
    	    printf("%lli\n", ans);
    	}
    	return 0;
    }
      

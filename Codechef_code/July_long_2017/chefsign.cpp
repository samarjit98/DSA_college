#include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	int t;
    	scanf("%d \n", &t);
    	while(t--)
    	{
    	    string s;
    	    cin >> s;
    	    long long ans=1, pre=1, m=1;
    	    char sym=s[0];
    	    for(long long i=0; i<s.size(); i++)
    	    {
    	        if(s[i]=='<')
    	        {
    	            pre++; ans=pre;
    	        }
    	        else if(s[i]=='>')
    	        {
    	            if(pre==1)
    	            {
    	                ans++; 
    	            }
    	            else pre--;
    	        }
    	        m=max(ans, m);
    	        if(s[i]!='=')sym=s[i];
    	        
    	        if(s[i+1]=='<' && s[i]!='<' && sym=='>' && i<s.size()-1)
    	        {
    	            pre=1;
    	            ans=1;
    	        }
    	    }
    	    printf("%lli\n", m);
    	}
    	return 0;
    } 

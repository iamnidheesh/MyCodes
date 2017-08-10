

    #include <bits/stdc++.h>
    using namespace  std;
    #define lli long long int
    #define li long int
    int n;
    int a[101];
    int dp[101][3];
    int cal(int x,int ch) {
    	if(x == 0)
    		return 0;
    	if(dp[x][ch] != -1)
    		return dp[x][ch];
    	if(ch == 0) {
    		if(a[x-1] == 1 || a[x-1] == 3)
    			return dp[x][ch]  = min(cal(x-1,1),1 + cal(x-1,2));
    		else
    			return dp[x][ch] = 1 + cal(x-1,2);
    	}
    	else if(ch == 1) {	
    		if(a[x-1] == 2 || a[x-1] == 3)
    			return dp[x][ch] = min(cal(x-1,0),1 + cal(x-1,2));
    		else
    			return dp[x][ch] = 1 + cal(x-1,2);
    	}
    	else  {
    		if(a[x-1] == 0)
    			return dp[x][ch] = 1 + cal(x-1,2);
    		else if(a[x-1] == 1)
    			return dp[x][ch] = min(cal(x-1,1),1 + cal(x-1,2));
    		else if(a[x-1] == 2)
    			return dp[x][ch] = min(cal(x-1,0),1 + cal(x-1,2));
    		else
    			return dp[x][ch] = min(cal(x-1,0),cal(x-1,1));
    	}
    }
    int main()
    {
    	cin>>n;
    	memset(dp,-1,sizeof(dp));
    	for(int i = 0;i < n;i++)
    		scanf("%d",&a[i]);
    	if(a[n-1] == 0)
    		printf("%d",1 + cal(n-1,2));
    	else if(a[n-1] == 1)
    		printf("%d",min(cal(n-1,1),1 + cal(n-1,2)));
    	else if(a[n-1] == 2)
    		printf("%d",min(cal(n-1,0),1 + cal(n-1,2)));
    	else
    		printf("%d",min(cal(n-1,0),cal(n-1,1)));
        return 0;
    }

Language: C++

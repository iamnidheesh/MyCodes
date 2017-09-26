    #include <bits/stdc++.h>
    using namespace  std;
    #define lli long long int
    #define li long int
    int t,m,n;
    int a[101];
    int dp[10001][2];
    int cal(int x,int ch) {
    	if(x == 0 && ch == 0)
    		return 0;
    	else if(x == 0 && ch == 1)
    		return 1;
    	if(dp[x][ch] != -1)
    		return dp[x][ch];
    	if(ch == 0)
    		dp[x][ch] = 0;
    	else
    		dp[x][ch] = 1;
    	for(int i = 0;i < n;i++) {
    		if(x - a[i] >= 0 && ch == 0) {
    			dp[x][ch] = cal(x - a[i],abs(ch-1));
    			if(dp[x][ch] == 1)
    				break;
    		}
    		else if( x - a[i] >= 0 && ch == 1) {
    			dp[x][ch] = cal(x - a[i],abs(ch-1));
    			if(dp[x][ch] == 0)
    				break;
    		}
    	}
    	return dp[x][ch];
    }
    int main()
    {
    	cin>>t;
    	while(t--) {
    		memset(dp,-1,sizeof(dp));
    		cin>>m>>n;
    		for(int i = 0;i < n;i++)
    			cin>>a[i];
    		if(cal(m,0))
    			printf("Little Deepu\n");
    		else
    			printf("Kate\n");
    	}
        return 0;
    }
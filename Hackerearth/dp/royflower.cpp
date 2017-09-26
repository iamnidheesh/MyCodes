    #include <bits/stdc++.h>
    using namespace  std;
    #define lli long long int
    #define li long int
    int t,n;
    int p,x[101],y[101];
    int dp[10001][101];
    int main()
    {
        cin>>t;
        while(t--) {
            cin>>n>>p;
            memset(dp,0,sizeof(dp));
            for(int i = 0;i < n;i++) {
                scanf("%d%d",&x[i],&y[i]);
            }
            int tot_profit = -1000000,mincost = 1000000;
            for(int i = 0;i <= p;i++)
                for(int j = 0;j < n;j++) {
                    if(i - y[j] >= 0)
                        dp[i][j] = max(x[j] - y[j] + dp[i-y[j]][j-1],dp[i][j-1]);
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                    if(dp[i][j] > tot_profit || ((dp[i][j] == tot_profit) && mincost > i ) ) {
                        tot_profit = dp[i][j];
                        mincost = i;
                    }
                }
            printf("%d %d\n",mincost,p+dp[p][n-1]);
        }
        return 0;
    }
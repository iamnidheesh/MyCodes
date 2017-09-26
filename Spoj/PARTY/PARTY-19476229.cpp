#include <bits/stdc++.h>
using namespace std;
int N,C;
int cost[101],fun[101];
int dp[501][101];
int main() {
	while(1) {
		cin>>C>>N;
		if(N == 0 && C == 0)
			break;
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < N;i++) {
			scanf("%d%d",&cost[i],&fun[i]);
		}
		int tot_profit = -1;
		int mincost = 10000000;
		for(int i = 0;i <= C;i++)
                for(int j = 0;j < N;j++) {
                    if(i - cost[j] >= 0)
                        dp[i][j] = max(fun[j] + dp[i-cost[j]][j-1],dp[i][j-1]);
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
        mincost = C;
        for(int i = 0;i <= C;i++)
        	for(int j = 0;j < N;j++) {
        		if(dp[i][j] == dp[C][N-1] && i < mincost)
        			mincost = i;
        	}
        printf("%d %d\n",mincost,dp[C][N-1]);
	}
}
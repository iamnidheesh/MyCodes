#include<bits/stdc++.h>
using namespace std;
int t,k,m;
int dp[1010][55];
int a[55],b[55];
int vis[1010][55];
int cal(int x,int y) {

    if(x <= 0 || y == m )
        return 0;
    if(vis[x][y] == t)
        return dp[x][y];
    vis[x][y] = t;
    if(x - a[y] >= 0)
        return dp[x][y] = max(b[y]+cal(x-a[y],y+1),cal(x,y+1));
    else
        return dp[x][y] = cal(x,y+1);
}
int main() {
    scanf("%d",&t);
    while(t) {
        scanf("%d%d",&k,&m);
        //memset(dp,-1,sizeof(dp));
        for(int i = 0;i < m;i++)
            scanf("%d%d",&a[i],&b[i]);
        printf("Hey stupid robber, you can get %d.\n",cal(k,0));
        t--;
    }
}

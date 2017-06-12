#include<bits/stdc++.h>
using namespace  std;
int t;
int n,k;
int a[1010];
int dp[1010][1010];
int cal(int x,int y) {
    if(x >= n)
        return 0;
    if(dp[x][y] != -1)
        return dp[x][y];
    int p,q;
    p = cal(x+1,y);
    if(y - a[x] >= 0)
        q = a[x] + cal(x+2,y-a[x]);
    else
        q = 0;
    return dp[x][y] = max(p,q);

}
int main() {
    cin>>t;
    int c = 1;
    while(t--) {
        scanf("%d%d",&n,&k);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        printf("Scenario #%d: %d\n",c,cal(0,k));
        c++;
    }
}

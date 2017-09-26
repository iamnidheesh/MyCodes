#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
int a[23][23];
int dp[23][23];
int cal(int i,int j) {

    if(i == n && j == m)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == n)
        return dp[i][j] = a[i][j+1] + cal(i,j+1);
    if(j == m)
        return dp[i][j] = a[i+1][j] + cal(i+1,j);
    return dp[i][j] = min(a[i+1][j] + cal(i+1,j),a[i][j+1] + cal(i,j+1));


}
int main() {
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>x>>y;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            scanf("%d",&a[i][j]);
    cal(x,y);
    if(dp[x][y] <= a[x][y])
        printf("Y %d",a[x][y] - dp[x][y]);
    else
        printf("N");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int dp[2010][2010];
int vis[2010][2010];
int s,n;
pair <int,int> p[2010];
int cal(int x,int y) {
    if(x <= 0 || y > n-1)
        return 0;
    if(vis[x][y] != 0)
        return dp[x][y];
    vis[x][y] = 1;
    if(p[y].first > x)
        return dp[x][y] = cal(x,y+1);
    else
        return dp[x][y] = max(p[y].second + cal(x - p[y].first,y+1),cal(x,y+1));
}
int main() {

    cin>>s>>n;
    //memset(dp,-1,sizeof(dp));
    for(int i = 0;i < n;i++)
        scanf("%d%d",&p[i].first,&p[i].second);
    //sort(p,p+n);
    printf("%d",cal(s,0));

}

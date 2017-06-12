#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int t;
int dp[110][110];
int vis[110][110];
int h,w;
int cal(int r,int c) {
    if(r == h-1)
        return 0;
    if(vis[r][c] == t) return dp[r][c];
    vis[r][c] = t;
    int m;
    if(c > 0 && c < w-1)
        m = max(cal(r+1,c+1) + a[r+1][c+1],max(cal(r+1,c-1) + a[r+1][c-1],cal(r+1,c) + a[r+1][c]));
    if(c == 0)
        m = max(cal(r+1,c) + a[r+1][c],cal(r+1,c+1) + a[r+1][c+1]);
    if(c == w-1)
        m = max(cal(r+1,c) + a[r+1][c],cal(r+1,c-1) + a[r+1][c-1]);
    dp[r][c] = m;
    return dp[r][c];
}
int main() {
    cin>>t;
    while(t){
        int ans = 0;
        scanf("%d%d",&h,&w);
        for(int i = 0;i < h;i++)
            for(int j = 0;j < w;j++)
                scanf("%d",&a[i][j]);
        for(int i = 0;i < w;i++)
            ans = max(ans,cal(0,i) + a[0][i]);
        printf("%d\n",ans);
        t--;
    }
    return 0;
}

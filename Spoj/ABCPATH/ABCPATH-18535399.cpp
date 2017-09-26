#include<bits/stdc++.h>
using namespace std;
int dp[60][60];
char a[60][60];
int h,w;
int compute(int x,int y) {
    if(x == 0 || y == 0 || x == h+1 || y == w+1)
        return 0;
    if(dp[x][y] != -1)
        return dp[x][y];
    int m = 1;
        for(int i = -1;i <= 1;i++)
            for(int j = -1;j <= 1;j++) {
                if(i == 0 && j == 0)
                    continue;
                else if(a[x+i][y+j] == a[x][y] + 1)
                    m = max(m,1 + compute(x+i,y+j));
            }
   // printf("%d\n",m);
    return dp[x][y] = m;
}
int main() {
    int c = 0;
    int ans;
    while(1) {
        c++;
        ans = 0;
        scanf("%d%d",&h,&w);
        if(h == 0)
            break;
        memset(dp,-1,sizeof(dp));
        for(int i = 1;i <= h;i++)
            scanf("%s",a[i]+1);
        for(int i = 1;i <= h;i++)
            for(int j = 1;j <= w;j++)
                if(a[i][j] == 'A') {
                    memset(dp,-1,sizeof(dp));
                    ans = max(ans,compute(i,j));
                }
        printf("Case %d: %d\n",c,ans);
    }
}

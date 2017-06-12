#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int dp[10001][101][2];
int cal(int x,int y,int p) {
    if(y == 0 && x > n)
        return 1;
    else if(y == 0 && x <= n)
        return 0;
    if(dp[x][y][p] != -1)
        return dp[x][y][p];
   int x1 = x%10 == 9 ? x - 9 : x + 1;
   int x2 = (x/10)%10 == 9 ? x - 90 : x + 10;
   int x3 = (x/100)%10 == 9? x - 900 : x + 100;
   int x4 = (x/1000)%10 == 9? x - 9000 : x + 1000;
    //printf("%d %d %d %d\n",x1,x2,x3,x4);
    if(p == 1)
        dp[x][y][1] = cal(x1,y-1,0)||
                      cal(x2,y-1,0)||
                      cal(x3,y-1,0)||
                      cal(x4,y-1,0);
    else
        dp[x][y][0] = cal(x1,y-1,1)&&
                      cal(x2,y-1,1)&&
                      cal(x3,y-1,1)&&
                      cal(x4,y-1,1);

     return dp[x][y][p];
}
int main() {
    cin>>t;
    memset(dp,-1,sizeof(dp));
    while(t) {
        scanf("%d%d",&n,&m);
        int ans  = cal(n,m,1);
        memset(dp,-1,sizeof(dp));
        if(ans == 1)
            printf("Ada\n");
        else
            printf("Vinit\n");
        t--;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int k,l,m,n;
int dp[1000010][2];
bool cal(int x,int c) {
    if(x == 0 && c == 1)
        return false;
    else if( x == 0  && c == 0)
        return true;
    if(dp[x][c] != -1)
        return dp[x][c];
    int x1,x2,x3;
    if(c == 1) {
        x1 = false;
        x2 = false;
        x3 = false;
        if(x - k >= 0)
            x1 = cal(x - k,0);
        if(x - l >= 0)
            x2 = cal(x - l,0);
        x3 = cal(x - 1,0);
        dp[x][c] = x1||x2||x3;
    }
    else {
        x1 = true;
        x2 = true;
        x3 = true;
        if(x - k >= 0)
            x1 = cal(x - k,1);
        if(x - l >= 0)
            x2 = cal(x - l,1);
        x3 = cal(x - 1,1);
        dp[x][c] = x1&&x2&&x3;
    }
    return dp[x][c];
}
int main() {

    cin>>k>>l>>m;
    memset(dp,-1,sizeof(dp));
    while(m--) {
        scanf("%d",&n);
        bool ans = cal(n,1);
        if(ans)
            printf("A");
        else
            printf("B");
    }
    return 0;
}

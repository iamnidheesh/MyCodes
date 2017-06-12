#include<bits/stdc++.h>
using namespace std;
int dp[100010],c;
int n;
int cal(int x) {
    if(x == 0)
        return 0;
    if(dp[x] != 0)
        return dp[x];
    int m = INT_MAX;
    int d;
    for(int i = 49;i >= 1;i--) {
        d = i*i*i;
        if(x >= d)
            m = min(m,1 + cal(x - d));
    }
    return dp[x] = m;
}
int main() {

    dp[1] = 1,dp[2] = 2,dp[3] = 3,dp[4] = 4,dp[5] = 5,dp[6] = 6,dp[7] = 7;
    c = 0;
    while(scanf("%d",&n) != EOF) {
        c++;
        printf("Case #%d: %d\n",c,cal(n));
    }

    return 0;
}

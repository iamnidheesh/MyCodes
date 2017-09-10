#include<bits/stdc++.h>
using namespace std;
int dp[5001];
int main() {
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    dp[b] = 1;
    dp[a] = 1;
    dp[c] = 1;
    dp[0] = 0;
    int x = min(a,min(b,c));
    for(int i = 1;i < n;i++) {
        if(i + a <= n && dp[i] != 0)
            dp[i+a] = max(dp[i+a],1 + dp[i]);
        if( i + b <= n && dp[i] != 0)
            dp[i+b] = max(dp[i+b],1 + dp[i]);
        if(i + c <= n && dp[i] != 0)
            dp[i+c] = max(dp[i+c],1 + dp[i]);
    }

    printf("%d",dp[n]);
}
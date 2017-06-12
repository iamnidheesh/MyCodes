#include<bits/stdc++.h>
using namespace std;
long long int dp[100001],a[100001];
long long int N,t;
long long int cal(int n) {
    if(n >= N)
        return 0;
    if(dp[n] != -1) return dp[n];
    long long int s1 = 0,s2 = 0,s3 = 0;
    s1 = cal(n+2) + a[n];
    if(N - n >= 2)
        s2 = cal(n+4) + a[n+1]+a[n];
    if(N-n >= 3)
        s3 = cal(n+6) + a[n] + a[n+1] + a[n +2];
    return dp[n] = max(s1,max(s2,s3));
}

int main() {
    cin>>t;
    while(t--) {
        cin>>N;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i < N;i++)
            scanf("%lld",&a[i]);
        printf("%lld\n",cal(0));
    }
}


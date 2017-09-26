#include<bits/stdc++.h>
using namespace std;
long long int a[100001],cnt[100001];
int n;
long long int dp[100001];
int main() {
    cin>>n;
    for(int i = 0;i < n;i++) {
        scanf("%I64d",&a[i]);
        cnt[a[i]]++;
    }
    dp[0] = 0;
    dp[1] = cnt[1];
    for(int i = 2;i <= 100000;i++) {
        dp[i] = max(dp[i-1],dp[i-2] + i*cnt[i]);
    }
    printf("%I64d",dp[100000]);
}
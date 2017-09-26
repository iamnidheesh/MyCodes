#include<bits/stdc++.h>
using namespace std;
int c[5];
int x;
int k;
bool dp[100010];
int main() {
    cin>>x>>k;
    for(int i = 0;i < k;i++)
        cin>>c[i];
    for(int i = 1;i < k;i++)
      c[i] = c[i] + c[i-1];
    dp[0] = true;
    for(int i = 1;i <= x; i++)
        dp[i] = false;
    for(int i = 0;i < k;i++)
        for(int j = c[i];j <= x;j++)
            dp[j] |= dp[j-c[i]];
    if(dp[x])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

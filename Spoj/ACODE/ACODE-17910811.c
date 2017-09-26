#include<bits/stdc++.h>
using namespace std;
#define llu long long unsigned int
char s[5010];
llu dp[5010];
llu n;

llu code(int l) {
    if(l > n-1)
        return 1;
    if(dp[l] != 1) return dp[l];
    if(s[l] == '0')
        dp[l] = 0;
    else if(n - l >= 2) {
        if((s[l] == '2' && s[l+1] <= '6' || s[l] == '1' ))
            dp[l] = dp[l]*(code(l+2)+code(l+1));
        else
            dp[l] = dp[l]*code(l+1);
    }
    else
        dp[l] = dp[l]*code(l+1);
    return dp[l];
}
int main() {
    while(1) {
        scanf("%s",s);
        if(s[0] == '0')
            break;
        n = strlen(s);
        for(int i = 0;i < n;i++)
            dp[i] = 1;
        printf("%llu\n",code(0));
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
char s[100010];
int n;
long int dp[100010];
int t;
long int cal(char *x) {

    vector <int> last(256,-1);
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        dp[i] = (2*(dp[i-1]%1000000007))%1000000007;
        if(last[x[i-1]] != -1)
            dp[i] -= dp[last[x[i-1]]];
        if(dp[i] < 0)
            dp[i] += 1000000007;
        last[x[i-1]] = i-1;
    }
    return dp[n];
}
int main() {
    cin>>t;
    while(t--) {
        scanf("%s",s);
        n = strlen(s);
        printf("%ld\n",cal(s));
    }
}

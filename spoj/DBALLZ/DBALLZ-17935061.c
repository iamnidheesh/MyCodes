#include<bits/stdc++.h>
using namespace std;
int dp[1000001],e[1001],dt[1001],te,l;
int maxt(int el) {
    if(el == 0)
        return 0;
    if(dp[el] != -1) return dp[el];
    dp[el] = 0;
    for(int i = 0;i < l;i++) {
        if(el - e[i] >= 0)
           dp[el] = max(dp[el],maxt(el - e[i]) + dt[i]);
    }
    return dp[el];
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>te>>l;
        for(int i = 0;i < l;i++)
            scanf("%d",&e[i]);
        for(int i = 0;i < l;i++)
            scanf("%d",&dt[i]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",maxt(te));
    }

}

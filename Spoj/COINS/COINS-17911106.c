/* very nice problem
use dp for small no. and normal recursion for large*/
#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int dp[1000001];
long long int dollar(long long int m){
    if(m == 0)
        return 0;
    if(dp[m] != 0)
        return dp[m];
    dp[m] = max(m,dollar(m/2) + dollar(m/3) + dollar(m/4));
    return dp[m];
}
long long int rec(long long int m) {
    if(m <= 1000000)
        return dollar(m);
    return max(m,rec(m/2)+rec(m/3)+rec(m/4));
}
int main() {
   long long int ans;
    while(scanf("%lld",&n) != EOF) {
            if(n <= 1000000)
                ans = dollar(n);
            else
                ans = rec(n);
            printf("%lld\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string x,y;
int dp[6100][6100];
int lcs(int m,int n) {
    if(m == 0 || n == 0)
        return 0;
    if(dp[m][n] != -1) return dp[m][n];
    if(x[m-1] == y[n-1])
        return dp[m][n] = 1 + lcs(m-1,n-1);
    else
        return dp[m][n] = max(lcs(m-1,n),lcs(m,n-1));
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>x;
        y = x;
        memset(dp,-1,sizeof(dp));
        reverse(y.begin(),y.end());
        int l = x.size();
        printf("%d\n",l - lcs(l,l));
    }

}

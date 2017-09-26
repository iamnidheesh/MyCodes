//longest common subsequence
#include<bits/stdc++.h>
using namespace std;
int dp[2010][2010];
int x[2010];
int y[2010];
int l1,l2;
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
    int d,ans;
    cin>>d;
    while(d--) {
        l1 = 0;
        ans = 0;
        while(1) {
            scanf("%d",&x[l1]);
            if(x[l1] == 0)
                break;
            l1++;
        }
        while(1) {
            l2 = 0;
            while(1) {
                scanf("%d",&y[l2]);
                if(y[l2] == 0)
                    break;
                l2++;
            }
            if(l2 == 0)
                break;
            memset(dp,-1,sizeof(dp));
            ans = max(ans,lcs(l1,l2));
        }
        printf("%d\n",ans);
    }
}

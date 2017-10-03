#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n;
int a[22][3],dp[22][3];
int cal(int k,int ch) {
    if(k == n) {
        return 0;
    }
    if(dp[k][ch] != -1)
        return dp[k][ch];
    if(ch == 0)
        return dp[k][ch] = min(a[k][1] + cal(k+1,1),a[k][2] +cal(k+1,2));
    else if(ch == 1)
        return dp[k][ch] = min(a[k][0] + cal(k+1,0),a[k][2] + cal(k+1,2));
    else
        return dp[k][ch] = min(a[k][0] + cal(k+1,0),a[k][1] + cal(k+1,1));
}
int main()
{
    cin>>t;
    while(t--) {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i < n;i++) {
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        }
        printf("%d\n",min(min(a[0][0]+cal(1,0),a[0][1]+cal(1,1)),a[0][2]+cal(1,2)));
    }
    return 0;
}

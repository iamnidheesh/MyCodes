#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
/* use mcm
when order of picking elements is important
*/
int n;
int a[510];
int dp[510][510];
int main()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    for(int l = 1;l <= n;l++) {
        for(int i = 0;i + l <= n;i++) {
            int j = i + l;
            dp[i][j] = 1 + dp[i+1][j];
            for(int k = i+1; k < j;k++) {
                if(a[i] == a[k]) {
                    dp[i][j] = max(dp[i][j-1],dp[i+1][k] + dp[k+1][j]);
                }
            }
        }
    }
    cout<<dp[0][n];
    return 0;
}

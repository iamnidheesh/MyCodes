#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int c;
long long int dp[10][64];
long long int cal(int x,int y) {

    if(y == 0)
        return 1;
    if(dp[x][y] != -1)
        return dp[x][y];
    long long int ans = 0;
    for(int i = x;i <= 9;i++ )
        ans += cal(i,y-1);
    return dp[x][y] = ans;
}
int main() {
    cin>>t;
    while(t--) {
        scanf("%d%d",&c,&n);
        memset(dp,-1,sizeof(dp));
        printf("%d %lld\n",c,cal(0,n));
    }
    return 0;
}

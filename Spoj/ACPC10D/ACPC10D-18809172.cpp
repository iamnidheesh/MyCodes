#include<bits/stdc++.h>
using namespace std;
int n,k;
long long int dp[100001][3];
long long int a[100001][3];
int vis[100001][3];
long long int cal(int x,int i) {
    if(x == n-1)
        if(i == 0) {
            return a[n-1][0]+a[n-1][1];
        }
        else if(i == 1)
            return a[n-1][1];
        else if(i == 2)
            return 1e13;
    if(vis[x][i] == k)
        return dp[x][i];
    vis[x][i] = k;
    if(i == 0)
        return dp[x][i] = a[x][0] + min(cal(x+1,0),min(cal(x+1,1),cal(x,1)));
    if(i == 1)
        return dp[x][i] = a[x][1] + min(cal(x,2),min(cal(x+1,1),min(cal(x+1,0),cal(x+1,2))));
    if(i == 2) {
        return dp[x][i] = a[x][2] + min(cal(x+1,2),cal(x+1,1));
    }
}
int main() {
    k = 0;
    while(1) {
        scanf("%d",&n);
        k++;
        if(n == 0)
            break;
        for(int i = 0;i < n;i++)
            scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
        printf("%d. %lld\n",k,cal(0,1));
    }
}

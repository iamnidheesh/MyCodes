#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int a[1010];
int vis[1010][1010];
int n,t,ans2,ans1;
int cal(int l,int u) {
    if(u - l < 1)
        return 0;
    if(vis[l][u] == t)
        return dp[l][u];
    vis[l][u] = t;
    int m,k;
     if(a[l+1] >= a[u]) {
            m = a[l] + cal(l+2,u);
     }
     else {
            m = a[l] + cal(l+1,u-1);
     }
     if(a[l] >= a[u-1]) {
            k = a[u] + cal(l+1,u-1);
     }
     else {
            k = a[u] + cal(l,u-2);
     }
     return dp[l][u] = max(m,k);
}
int main() {
    while(1) {
        t++;
        scanf("%d",&n);
        if(n == 0)
            break;
        ans2 = 0;
        for(int i = 0;i < n;i++) {
            scanf("%d",&a[i]);
            ans2 += a[i];
        }
        ans1 = cal(0,n-1);
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",t,2*ans1-ans2);
    }
}

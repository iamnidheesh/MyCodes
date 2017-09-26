#include<bits/stdc++.h>
using namespace std;
int ct,t,n,k;
int cost[110];
int dp[110][110];
int vis[110][110];
int flag;
int min_cost(int kg,int N) {
    if(kg == 0)
        return 0;
    int m;
    int mc = 100001;
    flag = 0;
    if(vis[kg][N] == ct) return dp[kg][N];
    vis[kg][N] = ct;
    for(int i = 1;i <= kg;i++) {
        if(cost[i] != -1) {
                flag = 1;
                m = min_cost(kg-i,N-1) + cost[i];
                mc = min(mc,m);
        }
    }
    if(flag == 0)
        mc = -1;
    return dp[kg][N] = mc;
}
int main() {
    cin>>t;
     for(ct = 1;ct <= t;ct++){
        cin>>n>>k;
        for(int i = 1;i <= k;i++)
            scanf("%d",&cost[i]);
        printf("%d\n",min_cost(k,n));
    }
    return 0;
}

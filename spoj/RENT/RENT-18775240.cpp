#include<bits/stdc++.h>
using namespace std;
int t,n,st,d,p;
vector < pair < pair <int,int> , int > > v;
int dp[10010];
int cal(int i) {

    if(i == n)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int m = 0;
    for(int j = i+1;j < n;j++) {
        if(v[i].first.second <= v[j].first.first)
            m = max(m,cal(j)+v[j].second);
    }
    return dp[i] = m;
}
int main() {
    cin>>t;
    while(t--) {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i = 0;i < n;i++) {
            scanf("%d%d%d",&st,&d,&p);
            v.push_back(make_pair(make_pair(st,st+d),p));
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i = 0;i < n;i++) {
            ans = max(ans,cal(i) + v[i].second);
        }
        v.clear();
        printf("%d\n",ans);
    }
}

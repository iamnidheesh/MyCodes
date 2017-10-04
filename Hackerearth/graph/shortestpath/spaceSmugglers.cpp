#include <bits/stdc++.h>
using namespace std;
#define INF 200000001
int n,m,s,t,u,v,g;
vector <pair<int,int> > space[100002],rev[100002];
int fromS[100002],toS[100002],fromT[100002],toT[100002];
int dij(vector <pair<int,int> > * v,int s,int * dis) {
    priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > > pq;
    pq.push(make_pair(0,s));
    dis[s] = 0;
    int u;
    while(!pq.empty()) {

        u = (pq.top()).second;
        pq.pop();
        for( vector <pair <int,int> > :: iterator it = v[u].begin(); it != v[u].end();it++) {
            if(dis[u] + it->first < dis[it->second]) {
                dis[it->second] = dis[u] + it->first;
                pq.push(make_pair(dis[it->second],it->second));
            }
        }
    }
}
int main() {
    cin>>n>>m>>s>>t;

    for(int i = 1;i <= m;i++) {
        scanf("%d%d%d",&u,&v,&g);
        space[u].push_back(make_pair(g,v));
        rev[v].push_back(make_pair(g,u));
    }
    for(int i = 1;i <= n;i++)
        fromT[i] = INF,fromS[i] = INF,toT[i] = INF,toS[i] = INF;
    dij(space,s,fromS);
    dij(space,t,fromT);
    dij(rev,s,toS);
    dij(rev,t,toT);
    int ans = INF;
    for(int i = 1;i <= n;i++) {
        if(i != s && i != t)
            ans = min(ans,fromS[i]+toT[i]+fromT[i]+toS[i]);
    }
    if(ans != INF)
        printf("%d",ans);
    else
        printf("-1");
}
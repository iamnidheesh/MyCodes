/*very nice application
    shortest paths are composed of shortest paths
    1. to find shortest distance from every source to every vertex reachable
        from source apply Dijkstra
    2. to find shortest distance from every vertex to a particular destination
        reverse the graph and apply Dijkstra
     */
#include<bits/stdc++.h>
using namespace std;
int n,e,t,m,s,k,ans;
int a,b,w;
#define INF 300000000
int fromS[100005];
int toE[100005];
vector < pair <int,int> > f[10005];
vector < pair <int,int> > r[10005];
priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > > pq;
int dij(vector <pair<int,int> > * v,int s,int * dis) {
    pq = priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > >();
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
    cin>>t;
    while(t--) {
        ans = INF;
        scanf("%d%d%d%d%d",&n,&m,&k,&s,&e);
        for(int i = 1;i <= n;i++) {
            f[i].clear();
            r[i].clear();
            fromS[i] = INF;
            toE[i] = INF;
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            f[a].push_back(make_pair(w,b));
            r[b].push_back(make_pair(w,a));
        }
        dij(f,s,fromS);
        dij(r,e,toE);
        ans = fromS[e];
        while(k--) {
            scanf("%d%d%d",&a,&b,&w);
            ans = min(ans,min(fromS[a]+w+toE[b],fromS[b]+w+toE[a]));
        }
        if(ans < INF)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
}



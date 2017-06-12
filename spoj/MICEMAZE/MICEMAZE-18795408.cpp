#include<bits/stdc++.h>
using namespace std;
int n,e,t,m;
int a,b,w,ans = 0;
vector <int> dis;
vector < pair <int,int> > v[101];
priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > > pq;
int dij() {

    pq.push(make_pair(0,e));
    dis[e] = 0;
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
    cin>>n>>e>>t>>m;
    for(int i = 0;i < m;i++) {
        scanf("%d%d%d",&a,&b,&w);
        v[b].push_back(make_pair(w,a));
    }
    dis.clear();
    for(int i = 0;i <= n;i++)
        dis.push_back(INT_MAX);
    dij();
    for(int i = 1;i <= n;i++) {
       // printf("%d ",dis[i]);
        if(dis[i] <= t)
            ans++;
    }
    printf("%d",ans);
}

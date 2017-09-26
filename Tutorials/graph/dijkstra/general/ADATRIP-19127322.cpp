#include<bits/stdc++.h>
using namespace std;
vector < pair <int,int> > graph[5*100001];
int m,n,q,l,x,y,s;
int dis[5*100001];
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
    cin>>n>>m>>q;
    for(int i = 0;i < m;i++) {
        scanf("%d%d%d",&x,&y,&l);
        graph[x].push_back(make_pair(l,y));
        graph[y].push_back(make_pair(l,x));
    }
    while(q--) {
        scanf("%d",&s);
        for(int i = 0;i < n;i++)
            dis[i] = 10000010;
        dij(graph,s,dis);
        int ans = 0,c = 0;
        for(int i = 0;i < n;i++) {
            if(ans < dis[i] && dis[i] != 10000010)
                ans = dis[i];
        }
        for(int i = 0;i < n;i++) {
            if(dis[i] == ans)
                c++;
        }
        printf("%d %d\n",ans,c);
    }
}

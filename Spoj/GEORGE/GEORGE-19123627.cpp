#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,g,x,y,l;
int gpath[1001],dis[1001],mark[1001];
pair <int,int> delay[1001][1001];
int v[1001][1001];
int dij() {
    priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > > pq;
    pq.push(make_pair(k,a));
    dis[a] = k;
    int u;
    while(!pq.empty()) {

        u = (pq.top()).second;
        pq.pop();
        for(int i = 1;i <= n;i++) {
            if(mark[u])
                break;
            if(v[u][i])
                if( (dis[u] <= delay[u][i].second) && (dis[u] >= delay[u][i].first)) {
                    if((v[u][i] + delay[u][i].second) < dis[i]) {
                        dis[i] = delay[u][i].second + v[u][i];
                        pq.push(make_pair(dis[i],i));
                       // printf("hello\n");
                    }
                }
                else {
                    if((dis[u] + v[u][i]) < dis[i]) {
                        dis[i] = dis[u] + v[u][i];
                        pq.push(make_pair(dis[i],i));

                    }
                }
        }
        mark[u] = 1;
        if(u == b)
            break;
    }
}
int main() {
    cin>>n>>m;
    cin>>a>>b>>k>>g;
    for(int i = 0;i < g;i++) {
        scanf("%d",&gpath[i]);
    }
    int block = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            delay[i][j] = make_pair(0,0);
    for(int i = 0;i < m;i++) {
        scanf("%d%d%d",&x,&y,&l);
        v[x][y] = l;
        v[y][x] = l;
    }
    for(int i = 0;i < g-1;i++) {
        delay[gpath[i]][gpath[i+1]] = make_pair(block,block + v[gpath[i]][gpath[i+1]]);
        delay[gpath[i+1]][gpath[i]] = make_pair(block,block + v[gpath[i]][gpath[i+1]]);
        block +=  v[gpath[i]][gpath[i+1]];
    }
    for(int i = 1;i <= n;i++)
        dis[i] = 1000010;
    dij();
    printf("%d",dis[b]-k);

}

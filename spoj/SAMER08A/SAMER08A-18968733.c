#include<bits/stdc++.h>
using namespace std;
#define INF 10000010
int n,m,s,d,flag;
int fromS[501],toE[501],dis[501];
vector < pair <int,int> > g[501];
vector < pair <int,int> > reverseg[501];
int dij(vector <pair<int,int> > * v,int s,int * dis) {
    priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > > pq;
    pq.push(make_pair(0,s));
    dis[s] = 0;
    int u;
    while(!pq.empty()) {
        u = (pq.top()).second;
        pq.pop();
        for( vector <pair <int,int> > :: iterator it = v[u].begin(); it != v[u].end();it++) {
            if((dis[u] + it->first < dis[it->second]) && it->first != -1) {
                dis[it->second] = dis[u] + it->first;
                pq.push(make_pair(dis[it->second],it->second));
            }
        }
    }
}
int main() {

    while(1) {
        scanf("%d%d",&n,&m);
        if(n == 0)
            break;
        scanf("%d%d",&s,&d);
        int u1,u2,w;
        for(int i = 0;i < n;i++) {
            fromS[i] = INF;
            toE[i] = INF;
            dis[i] = INF;
            g[i].clear();
            reverseg[i].clear();
        }
        for(int i = 0;i < m;i++) {
            scanf("%d%d%d",&u1,&u2,&w);
            g[u1].push_back(make_pair(w,u2));
            reverseg[u2].push_back(make_pair(w,u1));
        }
        dij(g,s,fromS);
        int shpath = fromS[d];
        flag = 1;
        if(shpath == INF)
            flag = 0;
        if(flag)
            dij(reverseg,d,toE);
        if(flag)
            for(int i = 0; i < n;i++)
                for(vector < pair <int,int> > :: iterator it = g[i].begin();it != g[i].end();it++) {
                    if((fromS[i] + it->first + toE[it->second]) == shpath)
                        it->first = -1;
                }
        if(flag)
            dij(g,s,dis);
        if(dis[d] == INF)
            printf("-1\n");
        else
            printf("%d\n",dis[d]);
    }
}

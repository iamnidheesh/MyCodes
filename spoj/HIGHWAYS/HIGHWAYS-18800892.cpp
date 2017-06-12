#include<bits/stdc++.h>
using namespace std;
int n,e,t,m,s;
int a,b,w;
vector <int> dis;
vector < pair <int,int> > v[100001];
priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > > pq;
int dij() {

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
        if(u == e)
            break;
    }
}

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m>>s>>e;
        for(int i = 1;i <= n;i++)
            v[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            v[a].push_back(make_pair(w,b));
            v[b].push_back(make_pair(w,a));
        }
        dis.clear();
        pq = priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > >();
        for(int i = 0; i <= n; i++)
            dis.push_back(INT_MAX);
        dij();
        if(dis[e] < INT_MAX)
            printf("%d\n",dis[e]);
        else
            printf("NONE\n");
    }
}


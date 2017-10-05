    #include <bits/stdc++.h>
    using namespace std;
    #define li long int
    #define INF 1000000000001
    int n,m,u,v;
    li w,dis[100001][2],vis[100001][2];
    vector <pair<li,int> > adj[100001];
    void moddij(vector <pair<li,int> > * v,int s,li dis [][2]) {
        priority_queue < pair <pair<li,int> ,pair<int,int> > , vector < pair <pair<li,int>,pair<int,int> > >,greater < pair <pair<li,int>,pair<int,int> > > > pq;
        pq.push(make_pair(make_pair(0,0),make_pair(s,0)));
        dis[s][0] = 0;
        dis[s][1] = 0;
        vis[s][0] = 1;
        int u,eo,hop,distance;
        while(!pq.empty()) {
     
            u = (pq.top()).second.first;
            eo = (pq.top()).second.second;
            hop = (pq.top()).first.second;
            distance = (pq.top()).first.first;
            pq.pop();
            for( vector <pair <li,int> > :: iterator it = v[u].begin(); it != v[u].end();it++) {
                
                int eonext,hopnext; 
                    eonext = ((it->first)%2 == 0 ? 2 : 1);
                    if(eo != eonext && eo != 0)
                        hopnext = hop + 1;
                    else
                        hopnext = hop;
                    
                if(distance + it->first < dis[it->second][0] || (distance + it->first == dis[it->second][0] && hopnext <= dis[it->second][1])) {
                    
                    dis[it->second][1] = hopnext;
                    dis[it->second][0] = dis[u][0] + it->first;
                    pq.push(make_pair(make_pair(dis[it->second][0],dis[it->second][1]),make_pair(it->second,eonext)));
                }
            }
        }
    }
     
    int main() {
        cin>>n>>m;
        for(int i = 1;i <= m;i++) {
            scanf("%d%d%ld",&u,&v,&w);
            adj[u].push_back(make_pair(w,v));
            adj[v].push_back(make_pair(w,u));
        }
        memset(vis,-1,sizeof(vis));
        for(int i = 1;i <= n;i++) {
            dis[i][0] = INF;
            dis[i][1] = INF;
        }
        moddij(adj,1,dis);
        printf("%ld %ld",dis[n][0],dis[n][1]);
    }
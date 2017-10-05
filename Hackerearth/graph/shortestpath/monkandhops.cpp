    #include <bits/stdc++.h>
    using namespace std;
    #define li long long int
    #define INF 1e18
    int n,m,u,b;
    li w,dis[100001][2];
    vector <pair<li,int> > v[100001];
    void moddij() {
        priority_queue < pair <pair<li,int> ,pair<int,int> > , vector < pair <pair<li,int>,pair<int,int> > >,greater < pair <pair<li,int>,pair<int,int> > > > pq;
        pq.push(make_pair(make_pair(0,0),make_pair(1,0)));
        dis[1][0] = 0;
        dis[1][1] = 0;
        int u,eo,hop,distance;
        pair <pair<li,int> ,pair<int,int> > p;
        while(!pq.empty()) {
            p = pq.top();
            u = p.second.first;
            eo = p.second.second;
            hop = p.first.second;
            distance = p.first.first;
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
            scanf("%d%d%lld",&u,&b,&w);
            v[u].push_back(make_pair(w,b));
            v[b].push_back(make_pair(w,u));
        }
        for(int i = 1;i <= n;i++) {
            dis[i][0] = INF;
            dis[i][1] = INF;
        }
        moddij();
        printf("%lld %lld",dis[n][0],dis[n][1]);
    }
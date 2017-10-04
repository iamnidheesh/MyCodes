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
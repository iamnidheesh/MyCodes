#include<bits/stdc++.h>
using namespace std;
vector < pair <int,int> > graph[101];
int m,n,q,l;
int dis[101];
int dij(vector <pair<int,int> > * v,int s,int d,int * dis) {
    priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > > pq;
    pq.push(make_pair(0,s));
    dis[s] = 0;
    int u;
    while(!pq.empty()) {

        u = (pq.top()).second;
        pq.pop();
        if(u == d)
            break;
        for( vector <pair <int,int> > :: iterator it = v[u].begin(); it != v[u].end();it++) {
            if(dis[u] + it->first < dis[it->second]) {
                dis[it->second] = dis[u] + it->first;
                pq.push(make_pair(dis[it->second],it->second));
            }
        }
    }
}
int main() {
    cin>>n>>m;
    string s,s1,s2;
    map <string,int> city;
    for(int i = 1;i <= n;i++) {
        cin>>s;
        city[s] = i;
    }
    for(int i = 0;i < m;i++) {
        cin>>s1>>s2>>l;
        graph[city[s1]].push_back(make_pair(l,city[s2]));
        graph[city[s2]].push_back(make_pair(l,city[s1]));
    }
    cin>>q;
    while(q--) {
        cin>>s1>>s2;
        for(int i = 1;i <= n;i++)
            dis[i] = 10000010;
        dij(graph,city[s1],city[s2],dis);
        printf("%d\n",dis[city[s2]]);
    }
}

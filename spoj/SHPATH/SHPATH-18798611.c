#include<bits/stdc++.h>
using namespace std;
int t,n,p,nr,cost,r;
char name1[11],name2[11],name[11];
priority_queue < pair<int,int> ,vector <pair<int,int> >,greater <pair<int,int> > > pq;
unordered_map <string,int> m;
int dis[10001];
vector < pair<int,int> > v[10001];
int dij(int s,int d) {

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
        if(u == d)
            break;
    }
}
int main() {
    cin>>t;
    while(t--) {
        scanf("%d",&n);
        m.clear();
        for(int i = 0;i <= n;i++)
            v[i].clear();
        for(int i = 0;i < n;i++) {
            scanf("%s",name);
            m[name] = i+1;
            scanf("%d",&p);
            while(p--) {
                scanf("%d%d",&nr,&cost);
                v[i+1].push_back(make_pair(cost,nr));
            }
        }
        scanf("%d",&r);
        while(r--) {
            pq = priority_queue < pair<int,int> ,vector <pair<int,int> >,greater <pair<int,int> > >();
            for(int i = 0;i <= n;i++)
                dis[i] = INT_MAX;
            scanf("%s%s",name1,name2);
            dij(m[name1],m[name2]);
            printf("%d\n",dis[m[name2]]);
        }
    //clear data..
    }
}

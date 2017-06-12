#include<bits/stdc++.h>
using namespace std;
int n,t,m,a,b;
long long int ans,w;
#define INF 2000000000
long long int fromS[1000005];
long long int toE[1000005];
vector < pair <long long int,int> > f[1000005];
vector < pair <long long int,int> > r[1000005];
priority_queue < pair <long long int,int> , vector < pair <long long int,int> >,greater < pair <long long int,int> > > pq;
int dij(vector <pair<long long int,int> > * v,long long int * dis) {
    pq = priority_queue < pair <long long int,int> , vector < pair <long long int,int> >,greater < pair <long long int,int> > >();
    pq.push(make_pair(0,1));
    dis[1] = 0;
    int u;
    while(!pq.empty()) {

        u = (pq.top()).second;
        pq.pop();
        for( vector <pair <long long int,int> > :: iterator it = v[u].begin(); it != v[u].end();it++) {
            if(dis[u] + it->first < dis[it->second]) {
                dis[it->second] = dis[u] + it->first;
                pq.push(make_pair(dis[it->second],it->second));
            }
        }
    }
}

int main() {
    cin>>t;
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++) {
            f[i].clear();
            r[i].clear();
            fromS[i] = INF;
            toE[i] = INF;
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%lld",&a,&b,&w);
            f[a].push_back(make_pair(w,b));
            r[b].push_back(make_pair(w,a));
        }
        ans = 0;
        dij(f,fromS);
        dij(r,toE);
        for(int i = 2;i <= n;i++)
            ans = ans + fromS[i] + toE[i];
        printf("%lld\n",ans);
    }
}

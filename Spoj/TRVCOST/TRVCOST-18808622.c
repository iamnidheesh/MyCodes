#include<bits/stdc++.h>
using namespace std;
int n,e,t,s;
int a,b,w;
vector <int> dis;
vector < pair <int,int> > v[501];
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
    }
}

int main() {

        cin>>n;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            v[a].push_back(make_pair(w,b));
            v[b].push_back(make_pair(w,a));
        }
        for(int i = 0; i <= 500; i++)
            dis.push_back(INT_MAX);
        cin>>s>>t;
        dij();
        while(t--) {
        scanf("%d",&e);
        if(dis[e] < INT_MAX)
            printf("%d\n",dis[e]);
        else
            printf("NO PATH\n");
        }
}



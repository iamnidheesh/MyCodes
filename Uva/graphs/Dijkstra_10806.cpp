#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,w;
#define INF 30000000
int v[110][110];
int dis[110];
int parent[110];
priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > > pq;
int dij(int v[][110],int s,int * dis) {
    pq = priority_queue < pair <int,int> , vector < pair <int,int> >,greater < pair <int,int> > >();
    pq.push(make_pair(0,s));
    dis[s] = 0;
    int u;
    while(!pq.empty()) {

        u = (pq.top()).second;
        pq.pop();
        for(int i = 1;i <= n;i++) {
            if(v[u][i] != 0 && dis[u] + v[u][i] < dis[i]) {
                dis[i] = dis[u] + v[u][i];
                parent[i] = u;
                pq.push(make_pair(dis[i],i));
            }
        }
    }
}
int main() {

    while(1) {
        cin>>n;
        int fhalf,shalf;
        if(n == 0)
            break;
        cin>>m;
        memset(v,0,sizeof(v));
        for(int i = 0;i < m;i++) {
            scanf("%d%d%d",&a,&b,&w);
            v[a][b] = w;
            v[b][a] = w;
        }
        
        for(int i = 1;i <= n;i++)
            dis[i] = INF;
        memset(parent,-1,sizeof(parent));
        dij(v,1,dis);
        if(dis[n] != INF)   
            fhalf = dis[n];
        else {
            printf("Back to jail\n");
            continue;
        }
        
       /*int temp = n;
       
        while(parent[temp] != -1) {
            v[temp][parent[temp]] = 0;
            v[parent[temp]][temp] = 0;
            temp = parent[temp];
        }*/

       /* for(int i = 1;i <= n;i++)
            dis[i] = INF;
        dij(v,1,dis);
        if(dis[n] != INF)
            shalf = dis[n];
        else {
            printf("Back to jail\n");
            continue;
        }*/

       // printf("%d\n",shalf+fhalf);

    }
}
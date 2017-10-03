#include <bits/stdc++.h>
using  namespace std;
#define INF 10000001
int k,n,a,b;
int dis[1001];
vector <int> adj[1001];
void moddij() {
	priority_queue < pair<int,int > , vector < pair<int,int > >,greater < pair<int,int >  > > pq;
	pq.push(make_pair(0,1));
	dis[1] = 0;
	while(!pq.empty()) {
		int u = (pq.top()).second;
		if(u == k)
			break;
		pq.pop();
		for(int i = 0;i < adj[u].size();i++) {
			int v = adj[u][i];
			int waitTime;
			if((dis[u]/(5*abs(u-v)))%2 == 0)  // low to high
				if(u > v)
					waitTime = 5*abs(u-v) - dis[u]%(5*abs(u-v));
				else
					if(dis[u]%(5*abs(u-v)) == 0)
						waitTime = 0;
					else
						waitTime =  2*5*abs(u-v) - dis[u]%(5*abs(u-v));
			else    						 // high to low 
				if(u < v)
					waitTime = 5*abs(u-v) - dis[u]%(5*abs(u-v));
				else                         
					if(dis[u]%(5*abs(u-v)) == 0)
						waitTime = 0;
					else
						waitTime =  2*5*abs(u-v) - dis[u]%(5*abs(u-v));

			if(dis[u] + waitTime + 5*abs(u-v) < dis[v]) {
				dis[v] = dis[u] + waitTime + 5*abs(u-v);
				pq.push(make_pair(dis[v],v));
			}
		}
	}
}
int main() {

	cin>>k>>n;
	for(int i = 0;i < n;i++) {
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 1;i <= k;i++)
		dis[i] = INF;
	moddij();
	printf("%d",dis[k]);
}
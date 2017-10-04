#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
int n,s,e;
int road[1255][1255],roadT[1255][1255];
int rail[1255][1255],railT[1255][1255];
int fromRoadS[1255],toRoadE[1255],fromRailS[1255],toRailE[1255];
void dij(int adj[][1255],int source,int *dis) {
	priority_queue < pair<int,int> , vector < pair <int,int> > , greater < pair <int,int> > > pq;
	dis[source] = 0;
	pq.push(make_pair(0,source));
	while(!pq.empty()) {
		int u = (pq.top()).second;
		pq.pop();
		for(int i = 1;i <= n;i++) {
			if(adj[u][i] != 0) {
				if(dis[u] + adj[u][i] < dis[i]) {
					dis[i] = dis[u] + adj[u][i];
					pq.push(make_pair(dis[i],i));
				}
			}
		}
	}
}

int main() {
	cin>>n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++) {
			scanf("%d",&road[i][j]);
			roadT[j][i] = road[i][j];
		}

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++) {
			scanf("%d",&rail[i][j]);
			railT[j][i] = rail[i][j];
		}
	
	for(int i = 1;i <= n;i++) {
		fromRailS[i] = INF;
		fromRoadS[i] = INF;
		toRoadE[i] = INF;
		toRailE[i] = INF;
	}

	cin>>s>>e;
	dij(road,s,fromRoadS);
	dij(railT,e,toRailE);
	dij(rail,s,fromRailS);
	dij(roadT,e,toRoadE);
	int ans = INF;
	for(int z = 1; z <= n;z++) {
		if(z != s && z != e) {
			
			ans = min(ans,min(fromRoadS[z]+toRailE[z],fromRailS[z]+toRoadE[z]));
		}
	}
	printf("%d",ans);

}
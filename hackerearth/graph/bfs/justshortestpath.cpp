#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
vector <int> adj[1001];
int dis[1001],N,M,X,Y,T,D;
void bfs(int y) {

	queue <int> q;
	q.push(y);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0;i < adj[u].size();i++) {
			int v = adj[u][i];
			if(dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
			else if (dis[v] > dis[u] + 1) {
				dis[v] = 1 + dis[u];
				q.push(v);
			}
		}
	}	
}

int main() {
	cin>>N>>M;
	memset(dis,-1,sizeof(dis));
	dis[1] = 0;
	while(M--) {
		scanf("%d",&T);
		if(T == 1) {
			scanf("%d",&D);
			printf("%d\n",dis[D]);
		}
		else {
			scanf("%d%d",&X,&Y);
			adj[X].push_back(Y);
			int flag = 0;
			if(dis[X] != -1) {
				if(dis[Y] == -1) {
					flag = 1;
					dis[Y] = 1 + dis[X];
				}
				else if(dis[X] + 1 < dis[Y]) {
					flag = 1;
					dis[Y] = 1+ dis[X];
				}
				if(flag) {
					bfs(Y);
				}
			}
		}
	}
}
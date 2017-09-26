/*	
	node which is the only node in its level is the common
	node among all shortest paths.
	removing this node increases the length of shortest path
*/
#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
#define INF 10000000
int N,M,X,Y;
vector <int> adj[100001];
int fromX[100001];
int toY[100001];
int tdis[100001];
int mark;
vector <int> snode[100001];
void bfs(int s,int *d) {

	queue <int> q;
	d[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0;i < adj[u].size();i++) {
			int v = adj[u][i];
			if(d[v] == -1 && v != mark) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}	
}

int main() {
	cin>>N>>M;
	memset(fromX,-1,sizeof(fromX));
	memset(toY,-1,sizeof(toY));
	while(M--) {
		scanf("%d%d",&X,&Y);
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}
	scanf("%d%d",&X,&Y);
	mark = 0;
	bfs(X,fromX);
	bfs(Y,toY);
	for(int i = 1;i <= N;i++) {
		if(fromX[i] && toY[i] && fromX[i] + toY[i] == fromX[Y]) {
			snode[fromX[i]].push_back(i);
		}
	}
	int ans = INF;
	for(int i = 1;i <= N;i++) {
		if(snode[i].size() == 1)
			ans = min(ans,snode[i][0])
	}
	if(ans == INF)
		printf("-1");
	else
		printf("%d",ans);
}
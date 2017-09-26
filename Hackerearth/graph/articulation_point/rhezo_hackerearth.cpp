#include <bits/stdc++.h>
using namespace std;
#define INF 100001
#define NIL -1
int n,m,x,y,q,p;
int vis[100001],low[100001],num[100001],parent[100001];
vector <pair <int,int> > edge;
vector <int> adj[100001];
void bridges(int u) {

	vis[u] = 1;
	static int time = 1;
	num[u] = low[u] = time;
	time += 1;
	int children = 0;
	for(int i = 0;i < adj[u].size();i++) {
		int v = adj[u][i];
		if(vis[v] == -1) {  // front edge
			parent[v] = u;
			children++;
			bridges(v);
			low[u] = min(low[u],low[v]);
	
		}
		else if (parent[u] != v) { // back edge
			low[u] = min(low[u],num[v]);
		}
	}
}
int main() {
	cin>>n>>m;
	memset(vis,-1,sizeof(vis));
	for(int i = 0;i < n;i++) {
		num[i] = 0;low[i] = INF;parent[i] = NIL;
	}
	for(int i = 0;i < m;i++) {
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		edge.push_back(make_pair(x,y));
	}
	for(int i = 0;i < n;i++) {
		if(vis[i] == -1) {
			bridges(i);
		}
	}
	cin>>q;
	while(q--) {
		cin>>p;
		p--;
		if(low[edge[p].first] > num[edge[p].second] || low[edge[p].second] > num[edge[p].first])
			printf("Unhappy\n");
		else
			printf("Happy\n");
	}
	
}
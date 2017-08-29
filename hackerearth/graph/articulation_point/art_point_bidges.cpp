#include <bits/stdc++.h>
using namespace std;
#define INF 100001
#define NIL -1
int n,m,x,y;
int vis[100001],low[100001],num[100001],parent[100001];
vector <int> ap;
vector <pair <int,int> > bg;
vector <int> adj[100001];
void find_art_bridges(int u) {

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
			find_art_bridges(v);
			low[u] = min(low[u],low[v]);
			if(parent[u] == NIL && children > 1)
				ap.push_back(u);
			if(parent[u] != NIL && low[v] >= num[u]) {
				ap.push_back(u);
			}
			if(low[v] > num[u])
				if(u < v)
					bg.push_back(make_pair(u,v));
				else
					bg.push_back(make_pair(v,u));
	
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
	}
	for(int i = 0;i < n;i++) {
		if(vis[i] == -1) {
			find_art_bridges(i);
		}
	}
	printf("%u\n",ap.size());
	sort(ap.begin(),ap.end());
	for(int i = 0;i < ap.size();i++)
		printf("%d ",ap[i]);
	printf("%u\n",bg.size());
	sort(bg.begin(),bg.end());
	for(int i = 0;i < bg.size();i++)
		printf("%d %d\n",bg[i].first,bg[i].second);
}
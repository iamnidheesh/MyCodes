#include <bits/stdc++.h>
using namespace std;
vector <int> adj[2*100001];
int n,x,y,vis[2*100001],col[2*100001],parent[2*100001];
void col_dfs(int x) {
	vis[x] = 1;
	int color = 1;
	for(int i = 0;i < adj[x].size();i++) {
		int v = adj[x][i];
		if(!vis[v]) {
			if(color == col[x] || (parent[x] != -1 && color == col[parent[x]])) {
				color++;
				if(color == col[x] || (parent[x] != -1 && color == col[parent[x]]))
					color++;
			}
			parent[v] = x;
			col[v] = color;
			col_dfs(v);
			color++;
		}
	} 
}
int main() {
	cin>>n;
	for(int i = 0;i < n-1;i++) {
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(parent,-1,sizeof(parent));
	col[1] = 1;
	col_dfs(1);
	set <int> s;
	for(int i = 1;i <= n;i++)
		s.insert(col[i]);
	printf("%lu\n",s.size());
	for(int i = 1;i <= n;i++) {
		printf("%d ",col[i]) ;
	}
}
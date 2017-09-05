#include <bits/stdc++.h>
using namespace std;
int n,m,q,x,y,w,num;
int vis[101][101];
vector <int> adj[101][101];
void dfs(int c,int x) {

	vis[c][x] = num;
	for(vector <int> :: iterator it = adj[c][x].begin(); it != adj[c][x].end();it++) {
		int i = *it;
		if(!vis[c][i]) {
			dfs(c,i);
		}
	}
}
int main() {

	cin>>n>>m;
	for(int i = 0;i < m;i++) {
		scanf("%d%d%d",&x,&y,&w);
		adj[w][x].push_back(y);
		adj[w][y].push_back(x);
	}
	cin>>q;
	memset(vis,0,sizeof(vis));
	for(int c = 1;c <= m;c++) {
		for(int i  = 1;i <= n;i++) {
				if(!vis[c][i]) {
					num = i;
					dfs(c,i);
				}
			}
	}
	while(q--) {
		cin>>x>>y;
		int ans = 0;
		for(int i = 1;i <= m;i++) {
			if(vis[i][x] == vis[i][y])
				ans++;
		}
		printf("%d\n",ans);
	}
}
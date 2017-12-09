#include <bits/stdc++.h>
using namespace std;
#define lli long long int
long int c[100001];
vector <int> adj[100001];
int vis[100001],n,m,x,y;
long int min_cost;
void dfs(int x) {
	vis[x] = 1;
	min_cost = min(min_cost,c[x]);
	for(int i = 0;i < adj[x].size();i++) {
		int y = adj[x][i];
		if(vis[y] == -1) {
			dfs(y);
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		scanf("%ld",&c[i]);
	}
	while(m--) {
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(vis,-1,sizeof(vis));
	lli ans = 0;
	for(int i = 1;i <= n;i++) {
		if(vis[i] == -1) {
			min_cost = 1e9;
			dfs(i);
			ans += (lli)min_cost;
		}
	}
	cout<<ans;
}
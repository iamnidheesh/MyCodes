#include <bits/stdc++.h>
using namespace std;
int n,m,y,x;
vector <int> adj[100001];
int state[100001],par[100001];
void dfs(int x) {

	state[x] = 1;
	for(vector <int> :: iterator it = adj[x].begin(); it != adj[x].end();it++) {
		int i = *it;
		if(!state[i]) {
			par[i] = x;
			dfs(i);
		}
	}
}
int main() {

	cin>>n;
		cin>>m;
		for(int i = 0;i < m;i++) {
			scanf("%d%d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			if(!state[i]) {
				dfs(i);
				ans--;
			}
		}
		for(int i = 1;i <= n;i++) {
			if(adj[i].size() > adj[par[i]].size()) {
				ans++;
			}
		}
		
		printf("%d",ans);
	
}
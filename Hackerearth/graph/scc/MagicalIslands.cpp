#include <bits/stdc++.h>
using namespace std;
int a,b,n,ct,m;
stack <int> st;
vector <int> adj[100001],rev[100001];
int vis[100001],scc[100001];
void dfs(int v) {
	vis[v] = 1;
	for(int i = 0;i < adj[v].size();i++) {
		int x = adj[v][i];
		if(!vis[x]) {
			dfs(x);
		}
	}
	st.push(v);
}
void revdfs(int v) {
	vis[v] = ct;
	scc[ct]++;
	for(int i = 0;i < rev[v].size();i++) {
		int x = rev[v][i];
		if(!vis[x]) {
			revdfs(x);
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i = 0;i < m;i++) {
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for(int i = 1;i <= n;i++)
		if(!vis[i])
			dfs(i);
	
	memset(vis,0,sizeof(vis));
	ct = 1;
	while(!st.empty()) {
		int i = st.top();
		st.pop();
		if(!vis[i]) {
			revdfs(i);
			ct++;
		}
	}
	int ans = 0;
	for(int i = 1;i < ct;i++)
		ans = max(ans,scc[i]);
	cout<<ans;
	
}
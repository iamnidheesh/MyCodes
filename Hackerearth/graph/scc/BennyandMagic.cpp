#include <bits/stdc++.h>
using namespace std;
int a,b,n,ct,m;
long int w;
stack <int> st;
vector <pair<long int,int> > adj[300001],rev[300001];
int vis[300001];
void dfs(int v) {
	vis[v] = 1;
	for(int i = 0;i < adj[v].size();i++) {
		int x = adj[v][i].second;
		if(!vis[x]) {
			dfs(x);
		}
	}
	st.push(v);
}
void revdfs(int v) {
	vis[v] = ct;
	for(int i = 0;i < rev[v].size();i++) {
		int x = rev[v][i].second;
		if(!vis[x]) {
			revdfs(x);
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i = 0;i < m;i++) {
		scanf("%d%d%ld",&a,&b,&w);
		adj[a].push_back(make_pair(w,b));
		rev[b].push_back(make_pair(w,a));
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
	
}
#include <bits/stdc++.h>
using namespace std;
int a,b,C,D,ct,n,m;
stack <int> st;
vector <int> adj[100001],rev[100001];
int vis[100001];
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
	vis[v] = 1;
	ct++;
	for(int i = 0;i < rev[v].size();i++) {
		int x = rev[v][i];
		if(!vis[x]) {
			revdfs(x);
		}
	}
	//st.push(v);
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
	C = 0,D = 0;
	while(!st.empty()) {
		int i = st.top();
		st.pop();
		ct = 0;
		if(!vis[i]) {
			revdfs(i);
			if(ct%2 == 0)
				D += ct;
			else
				C += ct;
		}
	}
	printf("%d",C-D);
}
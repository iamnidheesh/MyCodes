#include <bits/stdc++.h>
using namespace std;
int N,M,A,B;
vector <int> adj[10001];
int vis[10001];
int dfs(int x) {

	int u,v;
	vis[x] = 1;
	stack <int> st;
	st.push(x);
	int ct = 0;
	while(!st.empty()) {
		u = st.top();
		st.pop();
		ct++;
		for(int i = 0;i < adj[u].size();i++) {
			v = adj[u][i];
			if(!vis[v]) {
				vis[v] = 1;
				st.push(v);
			}
		}
	}
	return ct;
}
int main() {
	
	cin>>N>>M;
	while(M--) {
		scanf("%d%d",&A,&B);
		adj[A].push_back(B);
	}
	int ans = 0,ct;
	for(int i = 1;i <= N;i++) {
			memset(vis,0,sizeof(vis));
			ct = dfs(i);
			ans = max(ct,ans);
	}
	printf("%d",ans);

}
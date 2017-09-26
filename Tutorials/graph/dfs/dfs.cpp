void dfs(int x) {

	int u,v;
	vis[x] = 1;
	stack <int> st;
	st.push(x);
	while(!st.empty()) {
		u = st.top();
		st.pop();
		for(int i = 0;i < adj[u].size();i++) {
			v = adj[u][i];
			if(!vis[v]) {
				vis[v] = 1;
				st.push(v);
			}
		}
	}
}

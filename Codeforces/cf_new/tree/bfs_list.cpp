void bfs(int s) {

	queue <int> q;
	dis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0;i < adj[u].size();i++) {
			int v = adj[u][i];
			if(dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}	
}
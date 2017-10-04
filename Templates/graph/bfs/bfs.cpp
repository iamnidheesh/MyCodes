void bfs(int s) {

	queue <int> q;
	dis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0;i < n;i++) {
			if(a[u][i] && dis[i] == -1) {
				dis[i] = dis[u] + 1;
				q.push(i);
			}
		}
	}	
}

void bfs() {

	queue <int> q;
	dis[0] = 0;
	q.push(0);
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

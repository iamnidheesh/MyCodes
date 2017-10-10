#include <bits/stdc++.h>
using namespace std;
vector <int> adj[2010];
vector <int> root;
int p,n;
int dis[2010];
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
int main() {
	cin>>n;
	memset(dis,-1,sizeof(dis));
	for(int i = 1;i <= n;i++) {
		cin>>p;
		if(p == -1)
			root.push_back(i);
		else
			adj[p].push_back(i);
	}
	for(int i = 0;i < root.size();i++) {
		dis[root[i]] = 0;
		bfs(root[i]);
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		ans = max(ans,dis[i]);
	}
	printf("%d\n",ans+1);
}
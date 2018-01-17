#include <bits/stdc++.h>
using namespace std;
int n;
int a[2001][2001];
vector <int> adj[2001];
int dis[2001];
int findCycle(int s) {
	
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
			else if(dis[v] == 0)
				return dis[u]+1;
		}
	}
	return -1;
}
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++) {
			scanf("%d",&a[i][j]);
			if(a[i][j] == 1)
				adj[i].push_back(j);
		}
	for(int i = 1;i <= n;i++) {
		if(a[i][i] == 1) {
			printf("1\n");
			continue;
		}
		else  {
			bool flag = false;
			for(int j = 1;j <= n;j++) {
				if(j != i && a[i][j] == 1 && a[j][i] == 1) {
					flag = true;
					break;
				}
			}
			if(flag) {
				printf("2\n");;
				continue;
			}
		}
		memset(dis,-1,sizeof(dis));
		int ans;
		ans = findCycle(i);
		if(ans == -1)
			printf("NO WAY\n");
		else
			printf("%d\n",ans);
	}
}
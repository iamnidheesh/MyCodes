#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int vis[200][200];
char a[200][200];
bool check(int x,int y) {
	if(x >= 1 && x <= n && y >= 1 && y <= m)
		return true;
	else
		return false;
}
void bfs(int i,int j) {
	
	queue <pair<int,int> > q;
	q.push(make_pair(i,j));
	int u1,u2,v1,v2;
	int x[4] = {0,1,-1,0};
	int y[4] = {1,0,0,-1};
	while(!q.empty()) {
		u1 = q.front().first;
		u2 = q.front().second;
		q.pop();
		for(int k = 0;k < 4;k++) {
			v1 = u1 + x[k];
			v2 = u2 + y[k];
			if(check(v1,v2)) {
				if(vis[v1][v2] == -1) {
					vis[v1][v2] = 1 + vis[u1][u2];
					q.push(make_pair(v1,v2));
				}
				else if(vis[v1][v2] > 1 + vis[u1][u2]) {
					vis[v1][v2] = 1 + vis[u1][u2];
					q.push(make_pair(v1,v2));
				}
			}
		}
	}
}
int main() {

	cin>>t;
	while(t--) {
		cin>>n>>m;
		vector <pair <int,int> > v;
		memset(vis,-1,sizeof(vis));
		for(int i = 1;i <= n;i++)
			scanf("%s",a[i] + 1);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++) {
				if(a[i][j] == '1') {
					vis[i][j] = 0;
					v.push_back(make_pair(i,j));
				}
			}
		for(int i = 0;i < v.size();i++)
			bfs(v[i].first,v[i].second);
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				printf("%d ",vis[i][j]);
			}
			printf("\n");
		}
	}
}
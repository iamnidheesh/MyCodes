#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int n,m,x,y;
int a[1001][1001];
int dis[1001];
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
int main() {

	cin>>n>>m;
	memset(dis,-1,sizeof(dis));
	while(m--) {
		scanf("%d%d",&x,&y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	bfs();
	for(int i = 1;i < n;i++) {
		printf("%d\n",dis[i]);
	}
}
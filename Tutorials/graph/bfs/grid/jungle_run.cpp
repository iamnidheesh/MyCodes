#include <bits/stdc++.h>
using namespace std;
int n,dis[31][31];
char adj[31][31];
bool check(int x,int y) {
	if(x >= 0 && x < n && y >= 0 && y < n && adj[x][y] == 'P' && dis[x][y] == -1)
		return true;
	else
		return false;
}
int bfs(int sx,int sy,int ex,int ey) {
	queue < pair<int,int> > q;
	dis[sx][sy] = 0;
	q.push(make_pair(sx,sy));
	while(!q.empty()) {
		int ux = q.front().first,uy = q.front().second;
		q.pop();
		//printf("%d %d %d\n",ux,uy,dis[ux][uy]);
		if(make_pair(ux,uy) == make_pair(ex,ey))
			break;
		if(check(ux,uy+1))
			dis[ux][uy+1] = 1 + dis[ux][uy],q.push(make_pair(ux,uy+1));
		if(check(ux,uy-1))
			dis[ux][uy-1] = 1 + dis[ux][uy],q.push(make_pair(ux,uy-1));
		if(check(ux+1,uy))
			dis[ux+1][uy] = 1 + dis[ux][uy],q.push(make_pair(ux+1,uy));
		if(check(ux-1,uy))
			dis[ux-1][uy] = 1 + dis[ux][uy],q.push(make_pair(ux-1,uy));
	}
	return dis[ex][ey];
}
int main() {
	cin>>n;
	int sx,sy,ex,ey;
	memset(dis,-1,sizeof(dis));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++) {
			cin>>adj[i][j];
			if(adj[i][j] == 'S')
				sx = i,sy = j;
			if(adj[i][j] == 'E')
				ex = i,ey = j,adj[i][j] = 'P';
		}
	printf("%d\n",bfs(sx,sy,ex,ey));
}

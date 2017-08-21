#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int N,M,Q,X,Y;
int a[1001][1001];
int vis[1001][1001];
bool range(int x,int y) {
	if(x >= 1 && x <= N && y >= 1 && y <= M && a[x][y] && !vis[x][y])
		return true;
	else
		return false;
}

int bfs(int x,int y) {
	queue <pair <int,int> > q;
	q.push(make_pair(x,y));
	vis[x][y] = 1;
	int c = 1;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if(range(x-1,y)) {
			vis[x-1][y] = 1;
			q.push(make_pair(x-1,y));
			c++;
		}
		if(range(x,y-1)) {
			vis[x][y-1] = 1;
			q.push(make_pair(x,y-1));
			c++;
		}
		if(range(x+1,y)) {
			vis[x+1][y] = 1;
			q.push(make_pair(x+1,y));
			c++;
		}
		if(range(x,y+1)) {
			vis[x][y+1] = 1;
			q.push(make_pair(x,y+1));
			c++;
		}
	}
	return c;
}
int main()
{
	cin>>N>>M>>Q;
	int ans = 0;
	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= M;j++) {
			scanf("%d",&a[i][j]);
			if(a[i][j])
				ans++;
		}
	while(Q--) {
		scanf("%d%d",&X,&Y);
		if(!vis[X][Y] && a[X][Y]) {
			ans = ans - bfs(X,Y);
		}
		printf("%d\n",ans);
	}
    return 0;
}

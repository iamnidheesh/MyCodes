#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int T,N;
int a[21][21];
int vis[21][21];
int dis[21][21];
bool check(int x,int y) {
	if(x >= 1 && x <= N && y >= 1 && y <= N && !vis[x][y] && !a[x][y])
		return true;
	else
		return false;
}
int dfs(int x,int y) {
	if(x == N && y == N)
		return 1;
	vis[x][y] = 1;
	int a = 0,b = 0,c = 0,d = 0;
	if(check(x-1,y)) {
		a = dfs(x-1,y);
	}
	if(check(x+1,y)) {
		b = dfs(x+1,y);
	}
	if(check(x,y-1)) {
		c = dfs(x,y-1);
	}
	if(check(x,y+1)) {
		d = dfs(x,y+1);
	}
	vis[x][y] = 0;
	return a+b+c+d;
}
int main()
{
	cin>>T;
	while(T--) {
		cin>>N;
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= N;i++)
			for(int j = 1;j <= N;j++)
				scanf("%d",&a[i][j]);
		if(a[1][1] == 1 && a[N][N] == 1)
			printf("0\n");
		else {
			printf("%d\n",dfs(1,1));
		}
	}
    return 0;
}

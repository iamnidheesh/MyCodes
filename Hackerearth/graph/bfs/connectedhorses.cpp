#include <bits/stdc++.h>
using namespace  std;
#define MOD 1000000007
#define llu unsigned long long int
#define li long int
int T,N,M,Q,X,Y;
int a[1001][1001];
int vis[1001][1001];
bool range(int x,int y) {
	if(x >= 1 && x <= N && y >= 1 && y <= M)
		return true;
	else
		return false;
}

int findHorses(int x,int y) {

	queue <pair <int,int> > q;
	vis[x][y] = 1;
	int c = 1;
	q.push(make_pair(x,y));
	while(!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if(range(i-2,j-1) && a[i-2][j-1] != 0 && !vis[i-2][j-1]) {
	       vis[i-2][j-1] = 1;
	       c++;
	       q.push(make_pair(i-2,j-1));
	    }
	    if(range(i-2,j+1) && a[i-2][j+1] != 0 && !vis[i-2][j+1]) {
	       vis[i-2][j+1] = 1;
	       c++;
	       q.push(make_pair(i-2,j+1));
	    }
	    if(range(i-1,j-2) && a[i-1][j-2] != 0 && !vis[i-1][j-2] ) {
	       vis[i-1][j-2] = 1;
	       c++;
	       q.push(make_pair(i-1,j-2));
	    }
	    if(range(i-1,j+2) && a[i-1][j+2] != 0 && !vis[i-1][j+2]) {
	       vis[i-1][j+2] = 1;
	       c++;
	       q.push(make_pair(i-1,j+2));
	    }
	    if(range(i+1,j-2) && a[i+1][j-2] != 0 && !vis[i+1][j-2] ) {
	       vis[i+1][j-2] = 1;
	       c++;
	       q.push(make_pair(i+1,j-2));
	    }
	    if(range(i+1,j+2) && a[i+1][j+2] != 0 && !vis[i+1][j+2] ) {
	       vis[i+1][j+2] = 1;
	       c++;
	       q.push(make_pair(i+1,j+2));
	    }
	    if(range(i+2,j-1) && a[i+2][j-1] != 0 && !vis[i+2][j-1] ) {
	       vis[i+2][j-1] = 1;
	       c++;
	       q.push(make_pair(i+2,j-1));
	    }
	    if(range(i+2,j+1) && a[i+2][j+1] != 0 && !vis[i+2][j+1] ) {
	       vis[i+2][j+1] = 1;
	       c++;
	       q.push(make_pair(i+2,j+1));
	    }
	}
	return c;
}
llu fact(int x) {

	llu ans = 1;
	for(llu i = 2;i <= x;i++) {
		ans = ans*i;
		ans = ans%MOD;
	}
	return ans;
}

int main()
{	
	cin>>T;
	while(T--) {
		cin>>N>>M>>Q;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < Q;i++) {
			scanf("%d%d",&X,&Y);
			a[X][Y] = 1;
		}
		llu ans = 1;
		for(int i = 1;i <= N;i++)
			for(int j = 1;j <= M;j++) {
				if(a[i][j] && !vis[i][j]) {
					ans = ans*(fact(findHorses(i,j)));
					ans = ans%MOD;
				}
			}
		printf("%llu\n",ans);
	}
    return 0;
}

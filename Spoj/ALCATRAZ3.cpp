#include <bits/stdc++.h>
using namespace std;
int n,m,k,s1,s2;
cou
int vis[110][110];
char a[110][110];
pair <int,int> parent[110][110];
bool flag = false;
bool check(int x,int y) {
	if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '*')
		return true;
	else
		return false;
}
bool moddfs(int i,int j) {
	if(flag == true)
			return false;
	//printf("%d %d  length = %d\n",i,j,vis[i][j]);
	int x[4] = {1,-1,0,0};
	int y[4] = {0,0,-1,1};
	bool unmark = true;
	for(int q = 0;q < 4;q++) {
		int u = i + x[q];
		int v = j + y[q];
		if(check(u,v)) {
			if(vis[u][v] == -1) {
				unmark = false;
				if(make_pair(i,j) != make_pair(s1,s2))
					vis[u][v] = 1 + vis[i][j];
				else
					vis[u][v] = 1;
				parent[u][v] = make_pair(i,j);
				if(moddfs(u,v)) {
					unmark = true;
				}
			}
			else if(parent[i][j] != make_pair(u,v)){
				if(u == s1 && v == s2 ) {
				//	printf("Cycle %d\n",vis[s1][s2]);
					if(vis[s1][s2] < 1 + vis[i][j] ) {
						vis[s1][s2] = 1 + vis[i][j];
					//	printf("update Cycle %d\n",vis[s1][s2] );
						if(vis[s1][s2] >= k) {
							flag = true;
							return false;
						}
					}
				}
			}
		}
	}

	if(unmark) {
	//printf("unmark %d %d\n",i,j);
	vis[i][j] = -1;
	parent[i][j] = make_pair(-1,-1);
	}
	return unmark;
}
int main() { 
	cin>>n>>m>>k;
	cin>>s1>>s2;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin>>a[i][j];
	memset(vis,-1,sizeof(vis));
	if(a[s1][s2] == '*') {
		printf("NO");
		return 0;
	}
	vis[s1][s2] = 0;
	moddfs(s1,s2);	
	if(flag || k == 0)
		printf("YES");
	else
		printf("NO");
}
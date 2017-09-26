#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid[55][55];
int vis[55][55],flag = 0;
pair <int,int> parent[55][55];
bool check(int x,int y) {
	if(x >= 0 && x < n && y >= 0 && y < m)
		return true;
	else
		return false;
}
void dfs(int x,int y) {

	vis[x][y] = 1;
	int row[4] = {0,-1,0,1};
	int col[4] = {1,0,-1,0};
	for(int i = 0;i < 4;i++) {
		int u = x+row[i];
		int v = y+col[i];
		if(check(u,v) && grid[x][y] == grid[u][v]) {
			if(!vis[u][v]) {
				parent[u][v] = make_pair(x,y);
				dfs(u,v);
			}
			else if(parent[x][y] != make_pair(u,v)) {
				flag = 1;
			} 
		}
	}

}

int main() {

	cin>>n>>m;
	for(int i = 0;i < n;i++)
		scanf("%s",grid[i]);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			parent[i][j] = make_pair(-1,-1);
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(!vis[i][j]) {
				dfs(i,j);
			}
			if(flag == 1)
				break;
		}
		if(flag == 1)
			break;
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");

}
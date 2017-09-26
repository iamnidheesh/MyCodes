#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
long long int ct;
int vis[51];
vector <int> adj[51];
void dfs(int x) {

	vis[x] = 1;
	for(vector <int> :: iterator it = adj[x].begin(); it != adj[x].end();it++) {
		int i = *it;
		if(!vis[i]) {
			dfs(i);
		}
	}
}
int main() {

	cin>>n>>m;
	for(int i = 0;i < m;i++) {
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ct = 0;
	for(int i  = 1;i <= n;i++) {
		if(!vis[i]) {
			ct++;
			dfs(i);
		}
	}
	cout<< ((long long int)1 << ((long long int) n-ct))<<endl;
}
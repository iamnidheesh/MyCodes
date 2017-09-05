#include <bits/stdc++.h>
using namespace std;
int t,x,vis[100001];
long long int shake,n;
vector <int> adj[100001];
void dfs(int x) {

	for(int i = 0;i < adj[x].size();i++) {
		int v = adj[x][i];
		if(!vis[v]) {
			vis[v] = 1 + vis[x];
			shake += vis[v];
			dfs(v);
		}
	}
}
int main() {

	cin>>t;
	while(t--) {
		cin>>n;
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= n;i++)
			adj[i].clear();
		int root;
		for(int i = 1;i <= n;i++) {
			scanf("%d",&x);
			if(x == 0) {
				root = i;
				continue;
			}
			adj[x].push_back(i);
		}
	vis[1] = 0;
	shake = 0;
	dfs(root);
	cout<<shake<<" "<<(n*(n-1))/2 - shake<<endl;
	}
}
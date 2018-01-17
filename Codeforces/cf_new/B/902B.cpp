#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int n,p;
vector <int> adj[10001],toporder;
int c[10001],cv[10001],vis[10001];
void dfs(int v) {
	vis[v] = 1;
	for(int i = 0;i < adj[v].size();i++) {
		int x = adj[v][i];
		if(!vis[x]) {
			dfs(x);
		}
	}
	toporder.push_back(v); // reverse for toporder
}
void dfx(int v,int cx) {
	vis[v] = 1;
	cv[v] = cx;
	for(int i = 0;i < adj[v].size();i++) {
		int x = adj[v][i];
		if(!vis[x]) {
			dfx(x,cx);
		}
	}
}
int main() {
	cin>>n;
	for(int i = 2;i <= n;i++) {
		cin>>p;
		adj[p].push_back(i);
	}
	for(int i = 1;i <= n;i++)
		cin>>c[i];
	for(int i = 1;i <= n ;i++) {		
		if(!vis[i]) {
			dfs(i);
		}
	}
	int ans = 0;
	reverse(toporder.begin(),toporder.end());
	for(int i = 1;i <= n;i++) {
		if(cv[i] != c[i]) {
			memset(vis,0,sizeof(vis));
			dfx(i,c[i]);
			ans++;
		}
	}
	cout<<ans;

}
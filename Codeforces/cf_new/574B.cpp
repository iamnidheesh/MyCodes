#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,flag;
long long int ct,ans;
int vis[4001];
set <int> adj[4001];
vector <pair <int,int> > edge;
int main() {

	cin>>n>>m;
	for(int i = 0;i < m;i++) {
		scanf("%d%d",&x,&y);
		adj[x].insert(y);
		adj[y].insert(x);
		edge.push_back(make_pair(x,y));
	}
	ans = 15000;
	for(int i = 0;i < m;i++) {
		int v = edge[i].first,u = edge[i].second;
		int s = adj[v].size() + adj[u].size() - 4;
		for(set <int> :: iterator it = adj[u].begin();it != adj[u].end();it++) {
			if(adj[v].find(*it) != adj[v].end()) {
				if(s + adj[*it].size()-2 < ans) {
					ans = s + adj[*it].size() - 2;
				}
			}
		}
	}
	if(ans == 15000)
		printf("-1");
	else
		cout<<ans;
}
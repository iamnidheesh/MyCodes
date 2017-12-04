#include <bits/stdc++.h>
using namespace std;
#define li long int
int n,m,k,u,v;
li w;
vector <pair <li,int> > adj[100001];
map <int,int> storage;
int main() {
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++) {
		scanf("%d%d%ld",&u,&v,&w);
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}
	li ans = 1000000001;
	for(int i = 0;i < k;i++) {
		scanf("%d",&u);
		storage[u] = 1;
	}
	for(int i = 1;i <= n;i++) {
		if(storage[i] == 1) {
			for(int j = 0;j < adj[i].size();j++) {
				if(storage[adj[i][j].second] != 1 ) {
					ans = min(ans,adj[i][j].first);
				}
			}
		}
	}
	if(ans == 1000000001)
		cout<<"-1";
	else
		cout<<ans;

}
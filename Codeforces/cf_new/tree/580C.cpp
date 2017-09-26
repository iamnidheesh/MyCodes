#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
int cats[100001];
vector <int> adj[100001];
vector <int> leaf;
int parent[100001],vis[100001],maxcont[100001],currcont[100001];
void dfs(int x) {

	int u,v;
	vis[x] = 1;
	stack <int> st;
	st.push(x);
	while(!st.empty()) {
		u = st.top();
		//printf("%u\n",adj[u].size() );
		if(adj[u].size() == 1 && u != 1)
			leaf.push_back(u);
		st.pop();
		for(int i = 0;i < adj[u].size();i++) {
			v = adj[u][i];
			if(vis[v] == -1) {
				vis[v] = 1;
				if(cats[v])
					currcont[v] = 1 + currcont[u];
				else
					currcont[v] = 0;
				if(currcont[v] > maxcont[u])
					maxcont[v] = currcont[v];
				else
				        maxcont[v] = maxcont[u];
				parent[v] = u;
				st.push(v);
			}
		}
	}
}

int main() {

	cin>>n>>m;
	memset(vis,-1,sizeof(vis));
	memset(parent,-1,sizeof(parent));
	for(int i = 1;i <= n;i++)
		scanf("%d",&cats[i]);
	for(int i = 0;i < n-1;i++) {
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if(cats[1]) {
		maxcont[1] = 1;
		currcont[1] = 1;
	}
	dfs(1);
	int ans = leaf.size();
	for(int i = 0;i < leaf.size();i++) {
		if(maxcont[leaf[i]] > m)
			ans--;
	}
	printf("%d",ans);
}
// disjoint cliques
#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,flag = 1;
long long int ct,edges;
int vis[150001];
vector <int> adj[150001];
void dfs(int x) {

	int u,v;
	vis[x] = 1;
	ct++;
	edges = adj[x].size();
	stack <int> st;
	st.push(x);
	while(!st.empty()) {
		u = st.top();
		st.pop();
		for(int i = 0;i < adj[u].size();i++) {
			v = adj[u][i];
			if(!vis[v]) {
				vis[v] = 1;
				ct++;
				edges += adj[v].size();
				st.push(v);
			}
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
	
	for(int i = 1;i <= n;i++) {
		if(!vis[i]) {
			ct = 0;
			edges = 0;
			dfs(i);
			if(ct >= 3 && edges != ct*(ct-1)) {
				flag = 0;
				break;
			}
		}
	}
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
}
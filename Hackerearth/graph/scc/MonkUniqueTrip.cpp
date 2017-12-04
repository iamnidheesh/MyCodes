/*Note : longest path in a DAG formed by assuming scc as nodes*/
#include <bits/stdc++.h>
using namespace std;
int a,b,n,ct,m;
stack <int> st;
vector <int> adj[100001],rev[100001],tree[100001],toporder;
int vis[100001],order[100001],length_to[100001];
map < pair<int,int> ,int > mark;
int t = 1;
bool cmp(int p,int q) {
	return order[p] > order[q];
}
void dfs(int v) {
	vis[v] = 1;
	for(int i = 0;i < adj[v].size();i++) {
		int x = adj[v][i];
		if(!vis[x]) {
			dfs(x);
		}
	}
	st.push(v);
}
void revdfs(int v) {
	vis[v] = ct;
	for(int i = 0;i < rev[v].size();i++) {
		int x = rev[v][i];
		if(!vis[x]) {
			revdfs(x);
		}
	}
}
void treedfs(int v) {
	vis[v] = 1;
	for(int i = 0;i < tree[v].size();i++) {
		int x = tree[v][i];
		if(!vis[x]) {
			treedfs(x);
		}
	}
	order[v] = t;t = t+1;
}
int main() {
	cin>>n>>m;
	for(int i = 0;i < m;i++) {
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for(int i = 1;i <= n;i++)
		if(!vis[i])
			dfs(i);
	
	memset(vis,0,sizeof(vis));
	ct = 1;
	while(!st.empty()) {
		int i = st.top();
		st.pop();
		if(!vis[i]) {
			revdfs(i);
			ct++;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j < adj[i].size();j++) {
			int v = adj[i][j];
			if(!mark[{vis[i],vis[v]}] && vis[v] != vis[i]) {
				tree[vis[i]].push_back(vis[v]);
				mark[{vis[i],vis[v]}] = 1;
			}
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i = 1;i < ct;i++) {
		toporder.push_back(i);
		if(!vis[i]) {
			treedfs(i);
		}
	}
	sort(toporder.begin(),toporder.end(),cmp);
	for(int i = 0;i < toporder.size();i++) {
		for(int j = 0 ;j < tree[toporder[i]].size(); j++) {
			int v = tree[toporder[i]][j];
			if(length_to[v] <= length_to[toporder[i]] + 1)
				length_to[v] = length_to[toporder[i]] + 1;
		}
	}
	int ans = 0;
	for(int i = 1;i < ct;i++) {
		ans = max(ans,length_to[i]);
	}
	cout<<ans;
}
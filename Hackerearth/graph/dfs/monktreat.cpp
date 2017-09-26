#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int N,F,X,Y;
vector <int> adj[1001];
int vis[1001];
void dfs(int x) {

	int u,v;
	vis[x] = 1;
	stack <int> st;
	st.push(x);
	while(!st.empty()) {
		u = st.top();
		st.pop();
		for(int i = 0;i < adj[u].size();i++) {
			v = adj[u][i];
			if(!vis[v]) {
				vis[v] = 1;
				st.push(v);
			}
		}
	}
}
int main()
{
		cin>>N>>F;
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= N;i++)
			adj[i].clear();
		for(int i = 0;i < F;i++) {
			scanf("%d%d",&X,&Y);
			adj[X].push_back(Y);
		}
		int ans = 1001,ct;
		for(int i = 1;i <= N;i++) {
			memset(vis,0,sizeof(vis));
			dfs(i);
			ct = 0;
			for(int i = 1;i <= N;i++) {
				if(vis[i])
					ct++;
			}
			ans = min(ct,ans);
		}
		printf("%d\n",ans);
    return 0;
}

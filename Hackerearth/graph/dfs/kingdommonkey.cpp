#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int T,N,F,X,Y;
vector <int> adj[100001];
int vis[100001];
lli ban[100001];
lli dfs(int x) {

	int u,v;
	lli ct = 0;
	vis[x] = 1;
	stack <int> st;
	st.push(x);
	ct = ban[x];
	while(!st.empty()) {
		u = st.top();
		st.pop();
		for(int i = 0;i < adj[u].size();i++) {
			v = adj[u][i];
			if(!vis[v]) {
				vis[v] = 1;
				st.push(v);
				ct += ban[v];
			}
		}
	}
	return ct;
}
int main()
{
		cin>>T;
		while(T--) {
			cin>>N>>F;
			memset(vis,0,sizeof(vis));
			for(int i = 1;i <= N;i++)
				adj[i].clear();
			for(int i = 0;i < F;i++) {
				scanf("%d%d",&X,&Y);
				adj[X].push_back(Y);
				adj[Y].push_back(X);
			}
			for(int i = 1;i <= N;i++)
				scanf("%lld",&ban[i]);
			lli ans  = 0;
			for(int i = 1;i <= N;i++) {
				if(!vis[i])
					ans = max(ans,dfs(i));
			}
			printf("%lld\n",ans);
		}
    return 0;
}

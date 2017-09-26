#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int T,N,F,S,X,Y;
vector <int> adj[10001];
int vis[10001],slap[10001];
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
	cin>>T;
	while(T--) {
		cin>>N>>F>>S;
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= N;i++)
			adj[i].clear();
		for(int i = 0;i < F;i++) {
			scanf("%d%d",&X,&Y);
			adj[X].push_back(Y);
		}
		for(int i = 0;i < S;i++) {
			scanf("%d",&slap[i]);
			if(!vis[slap[i]])
				dfs(slap[i]);
		}
		int ans = 0;
		for(int i = 1;i <= N;i++) {
			if(vis[i])
				ans++;
		}
		printf("%d\n",ans);
	}
    return 0;
}

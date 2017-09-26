#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int N,M,X,Y;
int vis[100001];
vector <int> adj[100001];
vector <pair <int,int> > bad; 
void dfs() {
	stack <int> st;
	dis[1] = 0;
	st.push(1);
	while(!st.empty()) {
		int u = st.top();
		st.pop();
		for(int i = 0;i < adj[u].size();i++) {
			int v = adj[u][i];
			if(vis[])
		}
	}
}
int main()
{
	cin>>N>>M;
	for(int i = 0;i < M;i++) { 
		scanf("%d%d",&X,&Y);
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}
    return 0;
}

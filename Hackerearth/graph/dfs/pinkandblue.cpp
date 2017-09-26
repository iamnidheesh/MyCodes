#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int N,M,X,Y;
char g[100001];
int vis[100001];
vector <int> adj[100001];
bool isbipartite() {
	stack <int> st;
	st.push(1);
	vis[1] = 1;
	int u,v,mark;
	bool flag = true;
	while(!st.empty()) {
		u = st.top();
		st.pop();
		if(vis[u] == 1)
			mark = 2;
		else
			mark = 1;
		for(int i = 0;i < adj[u].size();i++) {
			v = adj[u][i];
			if(vis[v]) {
				if(vis[v] != mark) {
					flag = false;
					break;
				}
			}
			else {
					vis[v] = mark;
					st.push(v);
				}
		}
		if(!flag)
			break;
	}
	for(int i = 1;i <= N;i++)
		if(!vis[i]) {
			printf("%d\n",i);
			flag = false;
			break;
		}
	return flag;
}
int ans() {
	int count1 = 0,count2 = 0;
	for(int i = 1;i <= N;i++) {
		if(vis[i] == 1 && g[i] == 'B' || vis[i] == 2 && g[i] == 'G')
			count1++;
	}
	for(int i = 1;i <= N;i++) {
		if(vis[i] == 2 && g[i] == 'B' || vis[i] == 1 && g[i] == 'G')
			count2++;
	}
	return min(count1,count2);
}
int main()
{
	cin>>N>>M;
	for(int i = 1;i <= N;i++) {
		cin>>g[i];
	}
	for(int i = 0;i < M;i++) {
		scanf("%d%d",&X,&Y);
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}
	if(isbipartite()) {
		printf("%d",ans());
	}
	else 
		printf("Not possible");
    return 0;
}

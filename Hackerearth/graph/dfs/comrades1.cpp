#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int T,N,Q,X,Y;
int sup[100001];
int dis[100001];
vector < int > adj[100001];
pair <int,int> node_num[100001];
int pre = 1;
int post = 1;
void dfs(int x) {

	node_num[x].first = pre;
	pre++;
	for(int i = 0;i < adj[x].size();i++) {
		int v = adj[x][i];
		if(dis[v] == -1) {
			dis[v] = 1 + dis[x];
			dfs(v);
		}
	}
	node_num[x].second = post;
	post++;
}
int main()
{
	cin>>T;
	while(T--) {
		cin>>N;
		pre = 1;
		post = 1;
		for(int i = 1;i <= N;i++) {
			adj[i].clear();
		}
		memset(dis,-1,sizeof(dis));
		for(int i = 1;i <= N;i++) {
			scanf("%d",&sup[i]);
			if(sup[i]) {
				adj[sup[i]].push_back(i);
			}
			else {
				X = i;
			}
		}
		dis[X] = 0;
		dfs(X);
		cin>>Q;
		while(Q--) {
			scanf("%d%d",&X,&Y);
			if(node_num[X].first > node_num[Y].first
			 && node_num[X].second < node_num[Y].second)
				printf("%d\n",dis[X]-dis[Y]-1);
			else
				printf("-1\n");
		}
	}
    return 0;
}

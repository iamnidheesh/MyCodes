#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int N,Q,X,Y,P;
int dis[100001];
vector < int > adj[100001];
pair <int,int> node_num[100001];
int pre = 1,post = 1;
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
int main() {
	cin>>N;
	for(int i = 0;i < N-1;i++) {
		scanf("%d%d",&X,&Y);
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}
	memset(dis,-1,sizeof(dis));
	dfs(1);
	cin>>Q;
	while(Q--) {
		scanf("%d%d%d",&P,&X,&Y);
		if(P == 0) { //x ancistor of Y , YES
			if(node_num[X].first < node_num[Y].first && node_num[X].second > node_num[Y].second)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else {  // Y is ancistor of X , yes
			
			if(node_num[Y].first < node_num[X].first && node_num[Y].second > node_num[X].second)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}
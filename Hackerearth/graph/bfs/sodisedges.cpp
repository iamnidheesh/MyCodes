#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int N,M,K,U,V,X;
li dis[100001],T;
vector < int > adj[100001];
vector < pair <int,int> > edge;
map < li,vector < pair <int,int> > > tim;
map < pair <int,int> , int > block;
void bfs() {
	queue <int> q;
	dis[1] = 0;
	q.push(1);
	int u,v,flag;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		flag = 0;
		if(tim.find(dis[u]) != tim.end()) {
			flag = 1;
		}
		if(flag) {
			for(int i = 0;i < tim[dis[u]].size();i++) {
				block[tim[dis[u]][i]] = 1;
			}
		}
		for(int i = 0;i < adj[u].size();i++) {
			if(dis[adj[u][i]] == -1 && !block[make_pair(u,adj[u][i])]) {
				dis[adj[u][i]]  = dis[u] + 1;
				q.push(adj[u][i]);
			}
		}
	}
}
int main() {
	cin>>N>>M>>K;
	for(int i = 0;i < M;i++) {
		scanf("%d%d",&V,&U);
		edge.push_back(make_pair(U,V));
		adj[V].push_back(U);
		adj[U].push_back(V);
	}
	while(K--) {
		scanf("%ld%d",&T,&X);
		tim[T].push_back(edge[X-1]);
		tim[T].push_back(make_pair(edge[X-1].second,edge[X-1].first));
	}
	memset(dis,-1,sizeof(dis));
	bfs();
	printf("%ld",dis[N]);
}
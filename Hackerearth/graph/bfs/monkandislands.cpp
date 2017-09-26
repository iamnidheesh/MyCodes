#include <bits/stdc++.h>
using namespace std;
int T,N,M,X,Y;
vector<int> v[10001];
int dis[10001];
int bfs() {
	queue <int> q;
	q.push(1);
	dis[1] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vector<int> :: iterator  it;
		for(it = v[u].begin();it!=v[u].end();it++) {
			if(dis[*it] == -1) {
				dis[*it] = 1 + dis[u];
				q.push((*it));
			}
		}
	}
	return dis[N];
}
int main() {
	cin>>T;
	while(T--) {
		cin>>N>>M;
		for(int i = 1;i <= N;i++)
			v[i].clear();
		for(int i = 0;i < M;i++) {
			scanf("%d%d",&X,&Y);
			v[X].push_back(Y);
			v[Y].push_back(X);
		}
		memset(dis,-1,sizeof(dis));
		printf("%d\n",bfs());
	}
}
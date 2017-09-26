#include <bits/stdc++.h>
using namespace  std;
int N,Q;
long int d[1001];
long int X[100001];
long int maxval;
map <long int,int> vis;
void bfs() {
	vis[0] = 1;
	queue <int> q;
	q.push(0);
	while(!q.empty()) {
		long int u = q.front();
		q.pop();
		for(int i = 0;i < N;i++) {
			if(!vis[u + d[i]] && u + d[i] <= maxval) {
				vis[u+d[i]] = 1;
				q.push(u+d[i]);
			}
		}
	}
}
int main() {

	scanf("%d%d",&N,&Q);
	for(int i = 0;i < N;i++)
		scanf("%ld",&d[i]);
	maxval = 1;
	for(int i = 0;i < Q;i++) {
		scanf("%ld",&X[i]);
		maxval = max(maxval,X[i]);
	}
	bfs();
	for (int i = 0; i < Q; ++i)
	{
		if(vis[X[i]])
			printf("YES\n");
		else
			printf("NO\n");
	}
}
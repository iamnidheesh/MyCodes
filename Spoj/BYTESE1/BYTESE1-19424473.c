#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int K,M,N,a[101][101],X,Y,T;
int dis[101][101];
struct State
{
    int x, y, d;
    State() {}
    State(int a, int b, int c) { x = a; y = b; d = c; }
    bool operator>(const State &s) const { return d > s.d; }
};
void dijkstra() {
	priority_queue< State ,vector< State > ,greater <State> > pq;
	if(a[1][1] <= T){
		pq.push(State(1,1,a[1][1]));
		dis[1][1] = a[1][1];
	}
	while(!pq.empty()) {
		State s = pq.top();
		pq.pop();
		if(s.x - 1 >= 1)
			if(s.d + a[s.x-1][s.y] <= T)
				if(dis[s.x-1][s.y] > s.d + a[s.x-1][s.y]) {
					dis[s.x-1][s.y] = s.d + a[s.x-1][s.y];
					pq.push(State(s.x-1,s.y,dis[s.x-1][s.y]));
				}
		if(s.x + 1 <= M)
			if(s.d + a[s.x+1][s.y] <= T)
				if(dis[s.x+1][s.y] > s.d + a[s.x+1][s.y]) {
					dis[s.x+1][s.y] = s.d + a[s.x+1][s.y];
					pq.push(State(s.x+1,s.y,dis[s.x+1][s.y]));
				}
		if(s.y - 1 >= 1)
			if(s.d + a[s.x][s.y-1] <= T)
				if(dis[s.x][s.y-1] > s.d + a[s.x][s.y-1]) {
					dis[s.x][s.y-1] = s.d + a[s.x][s.y-1];
					pq.push(State(s.x,s.y-1,dis[s.x][s.y-1]));
				}
		if(s.y + 1 <= N)
			if(s.d + a[s.x][s.y+1] <= T)
				if(dis[s.x][s.y+1] > s.d + a[s.x][s.y+1]) {
					dis[s.x][s.y+1] = s.d + a[s.x][s.y+1];
					pq.push(State(s.x,s.y+1,dis[s.x][s.y+1]));
				}
	}
} 
int main() {
	cin>>K;
	while(K--) {
		cin>>M>>N;
		for(int i = 1;i <= M;i++)
			for(int j = 1;j <= N;j++)
				scanf("%d",&a[i][j]);
		cin>>X>>Y>>T;
		for(int i = 1;i <= M;i++)
			for(int j = 1;j <= N;j++)
				dis[i][j] = INF;
		dijkstra();
		if(dis[X][Y] == INF)
			printf("NO\n");
		else
			printf("YES\n%d\n",T - dis[X][Y]);
	}
}
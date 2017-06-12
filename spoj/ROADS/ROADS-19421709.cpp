#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
typedef pair<int,int> ii;
int t,K,N,R,S,D,L,T;
vector < pair<ii,int> > adj[101];
int dis[101][10001];
struct State
{
    int v, t, d;
    State() {}
    State(int a, int b, int c) { v = a; t = b; d = c; }
    bool operator>(const State &s) const { return d > s.d; }
};
int dijstra() {

	priority_queue< State,vector<State>,greater<State> > pq;
	for(int i = 1;i <= N;i++ )
		for(int j = 0;j <= K;j++)
			dis[i][j] = INF;

	pq.push(State(1,K,0));
	while(!pq.empty())  {
		State s = pq.top();
		pq.pop();
		if(dis[s.v][s.t] < s.d)
			continue;
		vector < pair<ii,int> > :: iterator it;
		for(it = adj[s.v].begin();it != adj[s.v].end();it++) {
			pair <ii,int> p = *it;
			int i = p.first.first,wt = p.first.second,coins = p.second;
			if(s.t - coins >= 0 ) {
				if(dis[i][s.t - coins] > s.d + wt) {
					dis[i][s.t - coins] = s.d + wt;
					pq.push(State(i,s.t-coins,s.d + wt));
				}
			}
		}
	}
	int ans = INF;
	for(int i = 0;i <= K;i++) {
		if(ans > dis[N][i])
			ans = dis[N][i];
	}
	if(ans == INF)
		return -1;
	else
		return ans;

}
int main() {
	cin>>t;
	while(t--) {
		cin>>K>>N>>R;
		for(int i = 1;i <  100;i++) {
			adj[i].clear();
		}
		for(int i = 0;i < R;i++) {
			scanf("%d%d%d%d",&S,&D,&L,&T);
			adj[S].push_back(make_pair(ii(D,L),T));
		}
		printf("%d\n",dijstra());
	}
}
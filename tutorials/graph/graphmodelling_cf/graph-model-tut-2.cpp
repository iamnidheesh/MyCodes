#include <bits/stdc++.h>
using namespace std;
#define add push_back
#define INF 1000000000
typedef pair<int,int> ii;
int N, M, A, B, W, v, d;
vector<ii> adj[10000];
int dist[10000][2];

struct State
{
	int v, p, d;
	State() {}
	State(int a, int b, int _c) { v = a; p = b; d = _c; }
	bool operator>(const State &s) const { return d > s.d; }
};

int dijkstra()
{
	for (int i = 0; i < N; i++) dist[i][0] = dist[i][1] = INF;
	priority_queue< State,vector<State>,greater<State> > pq;
	pq.push(State(0,0,0));
	dist[0][0] = 0;
	while (!pq.empty())
	{
		State s = pq.top(); pq.pop();
		if (dist[s.v][s.p] < s.d) continue;

		for (auto p : adj[s.v])
		{
			v = p.first; d = p.second;
			if (dist[v][s.p^1] > dist[s.v][s.p] + d)
			{
				dist[v][s.p^1] = dist[s.v][s.p] + d;
				pq.push(State(v,s.p^1,dist[v][s.p^1]));
			}
		}
	}
	return dist[N-1][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &A, &B, &W); A--; B--;
		adj[A].add(ii(B,W));
		adj[B].add(ii(A,W));
	}
	int ret = dijkstra();
	printf("%d\n", ret==INF?-1:ret);
}
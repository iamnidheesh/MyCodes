#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
vector <int> adj[100001];
int vis[100001],low[100001],num[100001],parent[100001];
int even,odd;
stack < pair<int,int> > st;
void biconnected(int u) {

	vis[u] = 1;
	int children = 0;
	static int time = 0;
	time++;
	num[u] = low[u] = time;
	for(int i = 0;i < adj[u].size();i++) {
		int v = adj[u][i];
		if(!vis[v]) {
			parent[v] = u;
			children++;
			st.push(make_pair(u,v));
			biconnected(v);
			low[u] = min(low[u],low[v]);
			if( (parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= num[u])) {
				int count = 0;
				while(st.top() != make_pair(u,v)) {
					st.pop();
					count++;
				}
				st.pop();
				count++;
				if(count%2 == 0)
					even++;
				else
					odd++;
			}
		}
		else if(parent[u] != v) {
			low[u] = min(low[u],num[v]);
			st.push(make_pair(u,v));
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i = 0;i < m;i++) {
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(parent,-1,sizeof(parent));
	even = 0,odd = 0;
	for(int i = 0;i < n;i++) {
		if(!vis[i]) {
			biconnected(i);
			if(!st.empty()) {
				if(st.size()%2 == 0)
					even++;
				else
					odd++;
				st = stack < pair <int,int> > ();
			}
		}
	}
	printf("%d %d",even,odd); // odd edges = even vertices and vice versa

}
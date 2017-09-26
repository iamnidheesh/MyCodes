#include <bits/stdc++.h>
using namespace std;
int n,m,y,x;
vector <int> adj[100001];
int state[100001];
void dfs(int x) {

	state[x] = 1;
	for(vector <int> :: iterator it = adj[x].begin(); it != adj[x].end();it++) {
		int i = *it;
		if(!state[i] && i != y) {
			dfs(i);
		}
	}
}
int main() {

	cin>>n;
		cin>>m;
		for(int i = 0;i < m;i++) {
			scanf("%d%d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		cin>>y;
		state[y] = 1;
		for(int i = 1;i <= n;i++) {
			if(i != y) {
				dfs(i);
				break;
			}
		}
		int flag = 1;
		for(int i = 0;i < n;i++) {
			if(state[i])
				continue;
			else {
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("Connected");
		else
			printf("Not Connected");
	
}
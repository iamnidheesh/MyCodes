#include <bits/stdc++.h>
using namespace std;
int n,m,y,x;
vector <int> adj[100001];
int state[100001];
vector <int> component[100001];
void dfs(int x,int con) {

	state[x] = con;
	component[con].push_back(x);
//	printf("hello\n");
	for(vector <int> :: iterator it = adj[x].begin(); it != adj[x].end();it++) {
		int i = *it;
		if(!state[i]) {
			dfs(i,con);
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
		int con = 0;
		for(int i = 1;i <= n;i++) {
			if(!state[i]) {
				con++;
				dfs(i,con);
			}
		}
		int ans = 0,temp;
		for(int i = 1;i <= con;i++) {
			temp = 0;
			for(int j = 0;j < component[i].size();j++) {
				temp += adj[component[i][j]].size();
			}
			ans = max(ans,temp/2);
		}
		printf("%d\n",ans);
	
}
#include <bits/stdc++.h>
using namespace std;
int t,x,y,z,n;
int tree[100001][2],vis[100001];
void dfs(int x) {
	vis[x] = 1;
	printf("%d ",x);
	if(!vis[tree[x][0]] && tree[x][0])
		dfs(tree[x][0]);
	if(!vis[tree[x][1]] && tree[x][1])
		dfs(tree[x][1]);
}
int main() {
	cin>>t;
	while(t--) {
		memset(tree,0,sizeof(tree));
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i = 1;i <= n;i++) {
			scanf("%d%d%d",&x,&y,&z);
			tree[x][0] = y;
			tree[x][1] = z;
		}
		dfs(1);
		cout<<endl;
	}
}
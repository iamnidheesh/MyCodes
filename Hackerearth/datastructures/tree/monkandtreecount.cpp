#include <bits/stdc++.h>
using namespace std;
int n,x,vis[510],post[510],pre[510],pre_num,post_num;
long int a[510],K;
vector <int> tree[510];
void dfs(int x) {
	vis[x] = 1;
	pre[x] = pre_num;
	pre_num++;
	for(int i = 0;i < tree[x].size();i++) {
		int v = tree[x][i];
		if(!vis[v]) {
			dfs(v);
		}
	}
	post[x] = post_num;
	post_num++;
}
int main() {
	cin>>n>>K;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= n-1;i++) {
		cin>>x;
		tree[x].push_back(i+1);
	}
	pre_num = 1;
	post_num = 1;
	dfs(1);
	int ans = 0;
	for(int i = 1;i < n;i++)
		for(int j = i+1;j <= n;j++)
			for(int k = 1;k <= n;k++) {
				if(pre[k] < pre[i] && post[k] > post[i] && pre[k] < pre[j] && post[k] > post[j]) {
					if(a[i]+a[j]+a[k] >= K) {
						ans++;
					}
				}
			}
	cout<<ans;

}
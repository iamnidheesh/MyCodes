#include <bits/stdc++.h>
using namespace std;
int tree[1001][2];
int parent[1001],vis[1001],child[1001];
int n,q,x,y;
char ch;
int main() {
	cin>>n>>q;
	memset(parent,-1,sizeof(parent));
	for(int i = 0;i < n-1;i++) {
		cin>>x>>y>>ch;
		parent[y] = x;
		if(ch == 'L') {
			tree[x][0] = y;
			child[y] = 0;
		}
		else {
			tree[x][1] = y;
			child[y] = 1;
		}
	}
	parent[1] = -1;
	while(q--) {
		cin>>x;
		stack <char> s;
		if(x == 1) {
			printf("1\n");
			continue;
		}
		else if(parent[x] == -1) {
			printf("-1\n");
			continue;
		}
		int temp = x;
		while(parent[temp] != -1) {
			s.push(child[temp]^1);
			temp = parent[temp];
		}
		int flag = 1;
		while(!s.empty()) {
			if(tree[temp][s.top()]) {
				temp = tree[temp][s.top()];
				s.pop();
			}
			else {
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("%d\n",temp);
		else
			printf("-1\n");
	}
}
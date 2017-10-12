#include <bits/stdc++.h>
using namespace std;
int n;
string name1,r,name2;
vector <int> tree[210];
map <string,int> m;
int num = 2;
int dis[210];
int bfs(int s) {

	queue <int> q;
	dis[s] = 0;
	q.push(s);
	int ans;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		ans = dis[u] + 1;
		for(int i = 0;i < tree[u].size();i++) {
			int v = tree[u][i];
			if(dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}	
	return ans;
}
int main() {
	cin>>n;
	memset(dis,-1,sizeof(dis));
	m["polycarp"] = 1;
	for(int i = 1;i <= n;i++) {
		cin>>name1>>r>>name2;
		for(int i = 0;i < name1.size();i++)
			name1[i] = tolower(name1[i]);
		for(int i = 0;i < name2.size();i++)
			name2[i] = tolower(name2[i]);
		m[name1] = num;
		num++;
		tree[m[name2]].push_back(m[name1]);
	}
	cout<<bfs(1);
}
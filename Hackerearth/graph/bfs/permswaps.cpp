#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int T,N,M,x,y;
vector <int> adj[100001];
int vis[100001],p[100001],q[100001],m[100001];
bool bfs(int x) {
	
	set <int> s1;
	set <int> s2;
	queue <int> q;
	q.push(x);
	s1.insert(p[x]);
	s2.insert(m[x]);
	vis[x] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vector <int> :: iterator it;
		for (it = adj[u].begin();it != adj[u].end();it++)
		{
			int v = *it;
			if(!vis[v] && m[v]) {
				vis[v] = 1;
				//printf("%d %d\n",m[v]);
				s1.insert(p[v]);
				s2.insert(m[v]); 
				q.push(v);
			}
		}
	}
	set <int> :: iterator it1,it2;
	bool flag = true;
	it1 = s1.begin();
	it2 = s2.begin();
	printf("\n");
	for(;it1 != s1.end();) {
	printf("%d %d\n",*it1,*it2);
		if(*it1 == *it2) {
			it1++;
			it2++;
		}
		else {
			it1++;
			it2++;
			flag = false;
			//break;
		}
	}
	return flag;
}
int main() {
	cin>>T;
	while(T--) {
		cin>>N>>M;
		memset(vis,0,sizeof(vis));
		memset(m,0,sizeof(m));
		for(int i = 1;i <= N;i++) {
			adj[i].clear();
			scanf("%d",&p[i]);
		}
		for(int i = 1;i <= N;i++) {
			scanf("%d",&q[i]);
			if(p[i] != q[i]) {
				m[i] = q[i];
			}
		}

		for(int i = 1;i <= M;i++) {
			scanf("%d%d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		map <int,int> :: iterator it;
		int flag = 1;
		for(int i = 1;i <= 100000;i++) {
			//printf("%d %d %d\n",p[it->first],it->first,it->second);
			if(!vis[i] && m[i])
				if(!bfs(i)) {

					flag = 0;
					//break;
				}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

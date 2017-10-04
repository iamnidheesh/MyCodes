#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
int n,m,s1,s2,d1,d2;
char s[1010][1010];
int dis[1010][1010];
void dij() {
	priority_queue < pair<int,pair<int,int> > , vector < pair <int,pair<int,int> > > , greater < pair <int,pair<int,int> > > > pq;
	dis[s1][s2] = 0;
	pq.push(make_pair(0,make_pair(s1,s2)));
	while(!pq.empty()) {
		int u1 = (pq.top()).second.first,u2 = (pq.top()).second.second;
		pq.pop();
		int x[4] = {-1,1,0,0};
		int y[4] = {0,0,-1,1};
		for(int i = 0;i < 4;i++) {
			int v1 = u1 + x[i],v2 = u2 + y[i];
			if(v1 >= 1 && v1 <= n && v2 >= 1 && v2 <= m) {
				if(dis[u1][u2] + abs(s[u1][u2]-s[v1][v2]) < dis[v1][v2]) {
					dis[v1][v2] = dis[u1][u2] + abs(s[u1][u2]-s[v1][v2]);
					pq.push(make_pair(dis[v1][v2],make_pair(v1,v2)));
				}
			}
		}
	}
}

int main() {

	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		scanf("%s",s[i]+1);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			dis[i][j] = INF;
	cin>>s1>>s2>>d1>>d2;
	dij();
	printf("%d",dis[d1][d2]);
}
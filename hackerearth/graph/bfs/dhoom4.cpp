#include <bits/stdc++.h>
using namespace std;
#define MOD 100000
#define li long int
// very nice problem 
int s,d,N;
int a[1001];
int dis[100001];
int bfs() {
	queue <li> q;
	dis[s] = 0;
	int flag = 0;
	if(s != d)
		q.push(s);
	while(!q.empty()) {
		li u = q.front();
		q.pop();
		for(int i = 0;i < N;i++) {
			li x = (u*a[i])%MOD;
			if(x == d) {
				dis[x] = dis[u] + 1;
				flag = 1;
				break;
			}
			if(dis[x] == -1) {
				dis[x] = 1 + dis[u];
				q.push(x);
			}
		}
		if(flag)
			break;
	}
	return dis[d];

}
int main() {
	cin>>s>>d;
	cin>>N;
	for(int i = 0;i < N;i++)
		scanf("%d",&a[i]);
	for(int i = 0;i <= 100000;i++)
		dis[i] = -1;
	printf("%d",bfs());
}
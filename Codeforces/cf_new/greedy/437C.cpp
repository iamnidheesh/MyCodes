#include <bits/stdc++.h>
using namespace std;
#define li long int
int n,m,x,y;
li v[1001];
li ans;

int main() {
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		scanf("%ld",&v[i]);
	}
	for(int i = 0;i < m;i++) {
		scanf("%d%d",&x,&y);
		if(v[x] > v[y])
			ans += v[y];
		else
			ans += v[x];
	}
	
	cout<<ans;
}
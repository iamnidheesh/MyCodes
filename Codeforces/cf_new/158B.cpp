#include <iostream>
#include <cstdio>
using namespace std;
int n,c[5],x;
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++) {
		scanf("%d",&x);
		c[x]++;
	}
	int ans = 0;
	ans += c[4];
	ans += c[3];
	c[1] = (c[1] > c[3] ? c[1] - c[3] : 0);
	ans += c[2]/2;
	if(c[2]%2 != 0) {
		c[2] = 1;
		ans++;
		c[1] -= 2;
		if(c[1] < 0)
			c[1] = 0;
	}
	if(c[1]%4 == 0)
		ans += c[1]/4;
	else
		ans += c[1]/4 + 1;
	cout<<ans;

}
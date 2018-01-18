#include <bits/stdc++.h>
using namespace std;
int q,l,r;
bool prime[1000001];
int ans[1000001];
void sieve(int n) {
	for(int i = 2;i*i <= n;i++) {
		if(prime[i] == true) {
			for(int j = 2*i ; j <= n;j += p) {
				prime[j] = false;
			}
		} 
	}
}

int main() {
	cin>>q;
	memset(prime,true,sizeof(p));
	sieve(1000000);
	ans[1] = 0;
	for(int i = 2;i <= 1000000;i++) {
		ans[i] = (prime[i] ? 1 : 0) + ans[i-1];
	}
	while(q--) {
		cin>>l>>r;
		if(l > r)
			printf("%d\n",ans[l] - ans[r-1] );
		else
			printf("%d\n",ans[r] - ans[l-1]);

	}
}
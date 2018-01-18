#include <bits/stdc++.h>
using namespace std;
int main() {
	int q,n;
	cin>>q;
	while(q--) {
		cin>>n;
		int ans = 0;
		for(int i = 1;i*i <= n;i++) {
			if(n%i == 0)
				ans += 2;
			if(i*i == n)
				ans -= 1;
		}
		cout<<ans<<endl;
	}
}
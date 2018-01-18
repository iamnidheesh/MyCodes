#include <bits/stdc++.h>
using namespace std;
int main() {
	int q,n;
	cin>>q;
	while(q--) {
		cin>>n;
		int ans = 1;
		if(n == 1)
			ans--;
		for(int i = 2;i*i <= n;i++) {
			if(n%i == 0)
				ans += i + n/i;
			if(i*i == n)
				ans -= i;
		}
		cout<<ans<<endl;
	}
}
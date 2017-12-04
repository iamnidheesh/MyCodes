#include <bits/stdc++.h>
using namespace std;
int t,n,pi;
long int a[101];
int main() {

	cin>>t;
	while(t--) {
		cin>>n;
		long int x = 0;
		for(int i = 1;i <= n;i++) {
			cin>>a[i];
			x ^= a[i];
		}
		if(x%2 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
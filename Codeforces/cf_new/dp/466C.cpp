#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int n;
lli a[5*100001],sl[5*100001],sr[5*100001];
int cntl[5*100001],cntr[5*100001],ctsum[5*100001];
int main() {
	cin>>n;
	lli sum = 0;
	for(int i = 1;i <= n;i++) { 
		cin>>a[i];
		sum += a[i];
	}
	if(n < 3 || sum%3 != 0) {
		cout<<0;
		return 0;
	}
	sl[1] = a[1];
	for(int i = 2;i <= n;i++) {
		sl[i] = sl[i-1] + a[i];
	}
	sr[n] = a[n];
	for(int i = n-1;i >= 1;i--) {
		sr[i] = sr[i+1] + a[i];
	}
	
	for(int i = 1;i <= n;i++) {
		if(sr[i] == sum/3)
			cntr[i] = 1;
		if(sl[i] == sum/3)
			cntl[i] = 1;
	}
	ctsum[n] = cntr[n];
	for(int i = n-1;i >= 1;i--) {
		ctsum[i] = ctsum[i+1] + cntr[i];
	}
	lli ans = 0;
	for(int i = 1;i <= n-2;i++) {
		if(cntl[i] == 1)
			ans += ctsum[i+2];
	}
	cout<<ans;
}
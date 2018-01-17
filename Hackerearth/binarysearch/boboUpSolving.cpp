#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[100001],m,n;
bool check(lli T) {
	int reqdays = 1;
	lli curr_sum = 0;
	for(int i = 0;i < n;i++) {
		if(curr_sum + a[i] > T) {
			curr_sum = a[i];
			reqdays += 1;
		}
		else {
			curr_sum += a[i];
		}
	}
	if(reqdays <= m)
		return true;
	else
		return false;
}
int main() {
	lli sum = 0,lo = 0,hi = 1e17,mid;
	cin>>n>>m;
	for(int i = 0;i < n;i++) {
		cin>>a[i];
		lo = max(lo,a[i]);
	}
	while(lo < hi) {
		mid = (lo + hi)/2;
		if(check(mid)) {
			hi = mid;
		}
		else 
			lo = mid+1;
	}
	cout<<lo;
}
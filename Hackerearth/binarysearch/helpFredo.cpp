#include <bits/stdc++.h>
using namespace  std;
#define lli unsigned long long int
#define li long int
lli n,a[100001];
double pdt;
bool check(lli val) {
	if(n*log((double)val) > pdt)
		return true;
	else
		return false;
}
int main()
{	
	cin>>n;
	pdt = 0;
	lli lo = 1e5,hi;
	for(int i = 0;i < n;i++) {
		cin>>a[i];
		pdt += log(a[i]); // log
		lo = min(lo,a[i]);
	}
	hi = 1e10;
	while(lo < hi) {
		lli mid = (lo+hi)/2;
		if(check(mid))
			hi = mid;
		else
			lo = mid+ 1;
	}
	cout<<lo;
    return 0;
}

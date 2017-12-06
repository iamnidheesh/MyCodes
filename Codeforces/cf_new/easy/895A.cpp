#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	int a[361],sum[361];
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	sum[1] = a[1];
	sum[0] = 0;
	for(int i = 2;i <= n;i++) {
		sum[i]  = sum[i-1] + a[i];
	}
	int ans = 365;
	for(int i = 1;i <= n;i++)
		for(int j = 0;j < i;j++) {
			ans = min(2*abs(180 -(sum[i]-sum[j])),ans);
		}
	cout<<ans;
}
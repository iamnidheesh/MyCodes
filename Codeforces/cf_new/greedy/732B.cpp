#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[501];
int main() {
	cin>>n>>k;
	for(int i = 0;i < n;i++)
		cin>>a[i];
	int ans = 0;
	for(int i = 1;i < n;i++) {
		if(a[i-1] + a[i] < k) {
			ans += k - a[i-1] - a[i];
			a[i] = k - a[i-1];
		}
	}
	cout<<ans<<endl;
	for(int i = 0;i < n;i++)
		cout<<a[i]<<" ";

}
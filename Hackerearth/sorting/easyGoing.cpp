#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int a[1001];
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>m;
		int k = n - m;
		for(int i = 0;i < n;i++)
			cin>>a[i];
		sort(a,a+n);
		int mi = 0,ma = 0;
		for(int i = 0;i < k;i++) {
			mi += a[i];
			ma += a[n-1-i];
		}
		cout<<ma-mi<<endl;
	}
}
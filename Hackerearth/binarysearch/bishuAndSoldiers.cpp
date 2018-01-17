#include <bits/stdc++.h>
using namespace std;
int n,q,m;
vector <int> v;
int a[10001];
int main() {
	cin>>n;
	for(int i = 0;i < n;i++) {
		cin>>m;
		v.push_back(m);
	}
	cin>>q;
	sort(v.begin(),v.end());
	a[0] = v[0];
	for(int i = 1;i < n;i++) {
		a[i] = v[i] + a[i-1];
	}
	while(q--) {
		cin>>m;
		int ans = upper_bound(v.begin(),v.end(),m) - v.begin();
		cout<<ans<<" "<<a[ans-1]<<endl;
	}
}
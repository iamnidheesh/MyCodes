#include <bits/stdc++.h>
using namespace std;
int n,q;
long int m;
vector <long int> v;
int main() {
	cin>>n;
	for(int i = 0;i < n;i++) {
		cin>>m;
		v.push_back(m);
	}
	cin>>q;
	sort(v.begin(),v.end());
	while(q--) {
		cin>>m;
		int ans = upper_bound(v.begin(),v.end(),m) - v.begin();
		cout<<ans<<endl;
	}
}
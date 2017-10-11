#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
set <int> s;
int main() {
	cin>>n>>m;
	for(int i = 1;i <= m;i++) {
		cin>>x>>y;
		s.insert(x);
		s.insert(y);
	}

	for(int i = 1;i <= n;i++) {
		if(s.find(i) == s.end()) {
			x = i;
			break;
		}
	}
	cout<<n-1<<endl;
	for(int i = 1;i <= n;i++) {
		if(i == x)
			continue;
		cout<<x<<" "<<i<<endl;
	}
}
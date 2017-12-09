#include <iostream>
#include <set>
using namespace std;
int n,a[2*100001];
set <int> s;
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	int ans = a[n];
	for(int i = n-1;i >= 1;i--) {
		if(a[i] != ans) {
			if(s.find(a[i]) == s.end()) {
				s.insert(ans);
				ans = a[i];
			}
		} 
	}
	cout<<ans;
}
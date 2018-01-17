#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	char ch = 'r';
	int ans = 0;
	for(int i = 1;i < n;i++) {
		if(ch == 'r') {
			if(a < b) {
				ch = 'o';
				ans += a;
			}
			else {
				ch = 'e';
				ans += b;
			}
		}
		else if(ch == 'o') {
			if(a < c) {
				ch = 'r';
				ans += a;
			}
			else {
				ch = 'e';
				ans += c;
			}
		}
		else if(ch == 'e') {
			if(c < b) {
				ch = 'o';
				ans += c;
			}
			else {
				ch = 'r';
				ans += b;
			}
		}
	}
	cout<<ans;
}
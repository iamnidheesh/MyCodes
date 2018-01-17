#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	int t;
	int x;
	cin>>t;
	while(t--) {
		cin>>x;
		bool flag = false;
		for(int i = 0;i <= 34;i++) {
			for(int j = 0;j <= 15;j++) {
				if(i*3 + j*7 == x) {
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
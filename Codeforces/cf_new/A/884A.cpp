#include <iostream>
using namespace std;
int main() {
	int n,t;
	int a[101];
	cin>>n>>t;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	int ans;
	for(int i = 1;i <= n;i++) {
		if(86400 - a[i] < t)
			t -= 86400 - a[i];
		else {
			ans = i;
			break;
		}
	}
	cout<<ans;
}
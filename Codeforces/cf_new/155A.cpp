#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n,a;
	cin>>n;
	cin>>a;
	int ma = a,mi = a,ans = 0;
	for(int i = 1;i < n;i++) {
		cin>>a;
		if(a > ma) {
			ans++;
			ma = a;
		}
		if(a < mi) {
			ans++;
			mi = a;
		}
	}
	cout<<ans;

}
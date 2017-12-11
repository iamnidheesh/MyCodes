#include <iostream>
using namespace std;
int n,k,x;
int a[101];
int main() {
	cin>>n>>k>>x;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	int ans = 0;
	for(int i = 1;i <= n - k;i++) {
		ans += a[i];
	}
	cout<<ans+k*x;
}
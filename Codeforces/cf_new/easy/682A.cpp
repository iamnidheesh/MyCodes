#include <iostream>
using namespace std;
int main() {
	long long int a,b;
	long long int ans = 0;
	cin>>a>>b;
	for(long long int i = 1;i <= a;i++) {
		ans += (b+i)/5 - i/5;
	}
	cout<<ans;
}
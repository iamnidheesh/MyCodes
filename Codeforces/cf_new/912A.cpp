#include <bits/stdc++.h>
using namespace std;
long long int a,b,x,y,z;
int main() {
	cin>>a>>b>>x>>y>>z;
	long long int a1 = x*2 + y ,b1 = y + 3*z;
	long long int ans = 0;
	if(a1 > a)
		ans = a1 - a;
	if(b1 > b)
		ans += b1 - b;
	cout<<ans;

}
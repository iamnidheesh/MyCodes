#include <iostream>
using namespace std;
int k,l,m,n,d;
int a[100001];
int main() {
	cin>>k>>l>>m>>n>>d;
	int ans = 0;
	for(int i = l;i <= d;i+=l)
		a[i] = 1;
	for(int i = m;i <= d;i+=m)
		a[i] = 1;
	for(int i = n;i <= d;i+=n)
		a[i] = 1;
	for(int i = k;i <= d;i+=k)
		a[i] = 1;
	for(int i = 1;i <= d;i++)
		if(a[i])
			ans++;
	cout<<ans;

}
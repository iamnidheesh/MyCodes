#include <bits/stdc++.h>
using namespace std;
#define lli long long int
long int x[100001],y[100001],n;
int main() {
	cin>>n;
	int p = 0,q = 0;
	for(int i = 1;i <= n;i++) {
		cin>>x[i]>>y[i];
		if(x[i] > 0)
			p++;
		else
			q++;
	}
	if(p == 0 || p == 1 || q == 0 || q == 1)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;

}
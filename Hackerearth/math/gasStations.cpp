#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
long int n,x,a[101];

int main()
{
	cin>>n>>x;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		if(a[i] < x) 
			ans++,x -= a[i];
		else {
			ans++;
			break;
		}
	}
	cout<<ans;
    return 0;
}

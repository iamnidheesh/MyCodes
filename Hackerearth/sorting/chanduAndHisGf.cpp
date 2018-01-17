#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n;
long int a[100001];
int main()
{
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 0;i < n;i++)
			cin>>a[i];
		sort(a,a+n,greater <long int> ());
		for(int i = 0;i < n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
    return 0;
}

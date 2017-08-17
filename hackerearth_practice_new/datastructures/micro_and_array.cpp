#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n,k;
int a[1000001];
int main()
{
	cin>>t;
	while(t--) {
		int x;
		cin>>n>>k;
		x = 1000001;
		for(int i = 0;i < n;i++)  {
			scanf("%d",&a[i]);
			x = min(x,a[i]);
		}
		printf("%d\n",max(k-x,0));

	}
    return 0;
}

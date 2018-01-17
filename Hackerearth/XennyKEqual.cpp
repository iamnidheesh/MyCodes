#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n;
lli a[1000001],k;
lli comb(lli x) {
	return (x*(x-1)*(x-2))/6;
}
int main()
{
	cin>>t;
	while(t--) {
		cin>>n>>k;
		int count = 0;
		for(int i = 0;i < n;i++) {
			scanf("%lld",&a[i]);
			if(a[i] == k)
				count++;
		}
		if(count < 3)
			printf("0/1\n");
		else {
			lli x,y;
			lli gcd = __gcd(x = comb(n),y = comb(count));
			printf("%lld/%lld\n",y/gcd,x/gcd);
		}
	}
    return 0;
}

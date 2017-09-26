#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int n;
li h[100001],dp[100001];
int main()
{
	cin>>n;
	for(int i = 0;i < n;i++) {
		scanf("%ld",&h[i]);
	}
	dp[0] = 1;
	li ans = 0; 
	for(int i = 1;i < n;i++) {
		if(h[i] > h[i-1])
			dp[i] = 1 + dp[i-1];
		else
			dp[i] = 1;

	}
	for(int i = n-2;i >= 0;i--) {
		if(a[i] > a[i+1] && t[i] <= t[i+1])
			t[i] = 1 + t[i+1];
	}
	for(int i = 0;i < n;i++) {
		sum += dp[i]; 
	}
	printf("%ld",ans);
    return 0;

}

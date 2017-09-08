#include <bits/stdc++.h>
using namespace std;
int t,n;
long int a[100001],dp[100001];
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		memset(dp,-1,sizeof(dp));
		for(int i = 0;i < n;i++) {
			scanf("%ld",&a[i]);
		}
		long int min_sum = a[0];
		dp[0] = a[0] < 0 ? 0 : a[0];
		for(int i = 1;i < n;i++)
			dp[i] = max(a[i] + dp[i-1],dp[i-1]),min_sum = max(min_sum,a[i]);
		long int curr_sum = a[0],max_sum = a[0];
		if(dp[n-1] == 0)
			dp[n-1] = min_sum; 
		for(int i = 1;i < n;i++) {
			if(curr_sum + a[i] < a[i] )
				curr_sum = a[i];
			else
				curr_sum += a[i];
			max_sum = max(curr_sum,max_sum);
		}
		printf("%ld %ld\n",max_sum,dp[n-1]);
	}
}
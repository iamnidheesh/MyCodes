#include <bits/stdc++.h>
using namespace std;
#define INF 1000
int m,s;
int dp[110][910];
int cal(int d,int sum) {

	if(d == 0) {
		if(sum == 0)
			return 0;
		else
			return -2;
	}

	if(dp[d][sum] != -1)
		return dp[d][sum];
	
	int x = -2;
	
	for(int i = 9;i >= 0;i--) {
		if(sum - i >= 0)
			x = cal(d-1,sum - i);
		if(x < 0)
			continue;
		else {
			dp[d][sum] = i;
			break;
		}
	}

	if(x < 0)
		dp[d][sum] = x;
	return dp[d][sum];
}
int calnext(int d,int sum) {

	if(d == 0) {
		if(sum == 0)
			return 0;
		else
			return -2;
	}

	if(dp[d][sum] != -1)
		return dp[d][sum];
	
	int x = -2;
	int f = 0;
	if(d == m && s > 0)
		f = 1;
	for(int i = f;i <= 9;i++) {
		if(sum - i >= 0) {
			x = calnext(d-1,sum - i);
			
		}
		if(x < 0)
			continue;
		else {
			dp[d][sum] = i;
			break;
		}
	}

	if(x < 0)
		dp[d][sum] = x;
	return dp[d][sum];
}
int main() {
	cin>>m>>s;
	memset(dp,-1,sizeof(dp));
	int ans = calnext(m,s);
	if(ans < 0 || (ans == 0 && m > 1) ) {
		cout<<-1<<" "<<-1;
		return 0;
	}
	int sum = s;
	for(int i = m;i > 0;i--) {
		cout<<dp[i][sum];
		sum -= dp[i][sum];
	}
	cout<<" ";
	memset(dp,-1,sizeof(dp));
	int next = cal(m,s);
	sum = s;
	for(int i = m;i > 0;i--) {
		cout<<dp[i][sum];
		sum -= dp[i][sum];
	}
	

}
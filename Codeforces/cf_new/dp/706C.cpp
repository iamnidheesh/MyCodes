#include <bits/stdc++.h>
using namespace std;
#define MAX 1e17
int n;
string s[100001];
long long int a[100001];
long long int dp[100001][2];
long long int solve(int index,int ch) {
	if(index == n+1)
		return 0;
	if(dp[index][ch] != -1)
		return dp[index][ch];
	long long int m = 1e17;
	if(ch == 0) {
		if(s[index].compare(s[index-1]) >= 0) {
			m = solve(index+1,0);
		}
			reverse(s[index].begin(),s[index].end());
			if(s[index].compare(s[index-1]) >= 0) {
				reverse(s[index].begin(),s[index].end());
				m = min(m,a[index] + solve(index+1,1));
			}
			else {
				reverse(s[index].begin(),s[index].end());
			}
	}
	else {
		int flag = 0;
		reverse(s[index-1].begin(),s[index-1].end());
		if(s[index].compare(s[index-1]) >= 0) {
			flag = 1;
			reverse(s[index-1].begin(),s[index-1].end());
			m = solve(index+1,0);
		}
			if(flag == 1)
				reverse(s[index-1].begin(),s[index-1].end());
			reverse(s[index].begin(),s[index].end());
			if(s[index].compare(s[index-1]) >= 0) {
				reverse(s[index].begin(),s[index].end());
				reverse(s[index-1].begin(),s[index-1].end());
				m = min(m,a[index] + solve(index+1,1));
			}
			else {
				reverse(s[index].begin(),s[index].end());
				reverse(s[index-1].begin(),s[index-1].end());
			}

	}
	return dp[index][ch] = m;
} 
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++)
		cin>>s[i];
	memset(dp,-1,sizeof(dp));
	long long int x = solve(2,0) , y = a[1] + solve(2,1);
	//cout<<x<<" "<<y<<endl;
	if(x >= MAX && y >= MAX) {
		cout<<-1;
	}
	else {
		cout<<min(x,y);
	}
}
#include <bits/stdc++.h>
using namespace std;
int v;
int a[10];
int dp[1000001];
int par[1000001];
map <int,int> p;
pair <int,int> seq[10];
bool cmp (pair <int,int> p1,pair<int,int> p2) {

	return p1 > p2;
}
int solve(int x) {

	if(x == 0) {
		return 0;
	}
	if(dp[x] != -1) {
		return dp[x];
	}
	int m = -1;
	for(int i  = 1;i <= 9;i++) {
		if(x - seq[i].second >= 0) {
			int k = 1 + solve(x - seq[i].second);
			if(k > m) {
				m = k;
				par[x] = seq[i].first;
			}
		}
	}
	return dp[x] = m;
}
int main() {
	cin>>v;
	for(int i = 1;i <= 9;i++) {
		cin>>a[i];
		seq[i].first = i;
		seq[i].second = a[i];
		p[i] = a[i];
	}
	memset(dp,-1,sizeof(dp));
	memset(par,-1,sizeof(dp));
	sort(seq+1,seq+10,cmp);
	if(solve(v) == -1 || v == 0) {
		cout<<-1;
		return 0;
	}
	int temp = v;
	while(par[temp] != -1) {
		cout<<par[temp];
		temp -= p[par[temp]];
	}
}
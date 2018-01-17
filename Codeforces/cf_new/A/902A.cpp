#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int n,m;
int a[101],b[101];
int vis[101];
int main() {
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>a[i]>>b[i];
	}
	if(a[1] != 0) {
		cout<<"NO";
		return 0;
	}
	bool flag = false;
	vis[0] = 1;
	for(int i = 1;i <= n;i++) {
		if(vis[a[i]] != 1) {
			flag = false;
			break;
		}
		for(int j = a[i];j <= b[i];j++) {
			vis[j] = 1;
			if(j == m) {
				flag = true;
				break;
			}
		}
		if(flag)
			break;
	}
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";

}
#include <bits/stdc++.h>
using namespace std;
int n,a[101];
int main() {
	cin>>n;
	int sum = 0;
	for(int i = 0;i < n;i++) {
		cin>>a[i];
		sum += a[i];
	}
	int temp = 0,ans = 0;
	sort(a,a+n,greater <int> ());
	for(int i = 0;i < n;i++) {
		temp += a[i];
		if(temp > sum - temp) {
			ans = i+1;
			break;
		}
	}
	cout<<ans;
}
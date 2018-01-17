#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int n;
int a[100001];
int freq[100001];
set <int> x;
int main() {

	cin>>n;
	cin>>a[1];
	x.insert(a[1]);
	freq[a[1]]--;
	int curr_max = a[1];
	for(int i = 2;i <= n;i++) {
		cin>>a[i];
		x.insert(a[i]);
		if(curr_max < a[i]) {
			curr_max = a[i];
			freq[a[i]]--;
		}
		else {
			freq[*(x.upper_bound(a[i]))]++;
		}

	}
	int ans = 0;
	int f = -2;
	for(int i = 1;i <= n;i++) {
		cout<<freq[i]<<endl;
		if(f < freq[i]) {
			f = freq[i];
			ans = i;
		}
	}
	cout<<ans;
}
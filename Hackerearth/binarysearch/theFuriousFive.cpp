#include <bits/stdc++.h>
using namespace std;
int t;
long int n;
vector <long int> v,a;
long int f(int x) {
	long int c = 0;
	while(x%5 == 0) {
		c++;
		x /= 5;
	}
	return c;
}
int main() {
	cin>>t;
	for(int i = 5; i <= 1000000000;i+=5) {
		long int ff = f(i+1);
		if(ff) {
			v.push_back();
			v[i] = v[i] + v[i-1];
			a.push_back(i);
		}
	}
	while(t--) {
		cin>>n;
		int ans = lower_bound(v.begin(),v.end(),n) - v.begin();
		cout<<a[ans]<<endl;

	}
}
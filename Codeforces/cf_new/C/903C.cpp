#include <bits/stdc++.h>
using namespace std;
#define lli long long int
long int a[5001];
int main() {
	int n;
	cin>>n;
	map <long int,int> m;
	long int maxnum = 0;
	for(int i = 0;i < n;i++) {
		cin>>a[i];
		m[a[i]]++;
	}
	int maxf = 0;
	for(map <long int,int> :: iterator it = m.begin();it != m.end();it++) {
		if(it->second > maxf) {
			maxf = it->second;
		}
	}
	cout<<maxf;
	
}
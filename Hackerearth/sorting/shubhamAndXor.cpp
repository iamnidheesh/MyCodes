#include <bits/stdc++.h>
using namespace std;
int n;
long int a[1000001];
unordered_map <long int,long int> m;
int main() {
	cin>>n;
	for(int i = 0;i < n;i++) {
		scanf("%ld",&a[i]);
		m[a[i]]++;
	}
	long int ans = 0;
	for(unordered_map <long int,long int> :: iterator it = m.begin();it != m.end();it++) {
	    if(it->second > 1) {
	        ans += ((it->second)*(it->second - 1))/2;
	    }
	}
	cout<<ans<<endl;

}
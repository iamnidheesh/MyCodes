#include <bits/stdc++.h>
using namespace  std;
int t,n;
string s;
vector <long int> v;
int main() {
	cin>>t;
	int flag;
	long int ans;
	while(t--) {
		ans = 0;
		cin>>n>>s;
		v.clear();
		for(int i = 0;i < n;i++) {
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'
			|| s[i] == 'u')
				v.push_back((long int)i + 1);
		}
		if(v.size() < 3) {
			printf("0\n");
			continue;
		}
		long int u = 2,l = 0;
		for(int i = 0;i < v.size()-2;i++) {
			ans += (v[l])*(n-v[u]+1);
			u++;
			l++;
		}
		printf("%ld\n",ans);
	}
}
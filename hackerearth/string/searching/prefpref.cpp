#include <bits/stdc++.h>
using namespace  std;
string p,s;
int main() {
	cin>>p>>s;
	int j = 0;
	int ans = 0;
	for(int i = 0;i < p.size();i++) {
		while(j < s.size()) {
			if(p[i] == s[j]) {
				ans++;
				j++;
				break;
			}
			j++;
		}
	}
	printf("%d",ans);
}
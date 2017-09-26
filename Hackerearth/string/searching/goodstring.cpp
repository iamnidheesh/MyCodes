#include <bits/stdc++.h>
using namespace  std;
string s;
int main() {
	cin>>s;
	int ans = 0,ct;
	for(int i = 0;i < s.size();i++) {
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'
			|| s[i] == 'u') {
			ct = 0;
			while(i < s.size() && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'
			|| s[i] == 'u')) {
				ct++;
				i++;
			}
			ans = max(ans,ct);
		}
	}
	printf("%d",ans);
}
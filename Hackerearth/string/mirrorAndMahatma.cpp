#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
	cin>>t;
	while(t--) {
		cin>>s;
		bool flag = true;
		for(int i = 0;i < s.size();i++) {
			if(s[i] == '0' || s[i] == '1' || s[i] == '8')
				continue;
			else {
				flag = false;
				break;
			}
		}
		string k = s;
		reverse(s.begin(),s.end());
		if(!flag) {
			cout<<"NO\n";
			continue;
		}
		else if(k == s)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	string c = "hello";
	int k = 0;
	bool flag = false;
	for(int i = 0;i < s.size();i++) {
		if(s[i] == c[k]) {
			k++;
			if(k == c.size()) {
				flag = true;
				break;
			}
		}
	}
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
}
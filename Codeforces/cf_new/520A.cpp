#include <iostream>
using namespace std;
int main() {
	int n;
	string s;
	cin>>n>>s;
	char c[26];
	for(int i = 0;i < n;i++) {
		if(s[i] - 'a' >= 0 && s[i] - 'a' < 26)
			c[s[i]-'a']++;
		else
			c[s[i] - 'A']++;
	}
	bool flag = true;
	for(int i = 0;i < 25;i++) {
		if(c[i] == 0) {
			flag = false;
			break;
		}
	}
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
}
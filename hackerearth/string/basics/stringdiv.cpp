#include <bits/stdc++.h>
using namespace  std;
int t;
string s;
set <char> check;
int main()
{
	cin>>t;
	while(t--) {
		cin>>s;
		check.clear();
		for(int i = 0;i < s.size();i++) {
			check.insert(s[i]);
		}
		if(s.size() < 4) {
			printf("NO\n");
			continue;
		}
		if( check.size() == 3 && s.size() > 4 || check.size() >= 4 
		    || check.size() == 2 && s.size() > 6 ||check.size() == 1 && s.size() > 9 ) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
    return 0;
}

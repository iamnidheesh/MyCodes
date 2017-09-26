#include <bits/stdc++.h>
using namespace  std;
int t;
string s;
int mark[30];
int main() {
	cin>>t;
	int ans,pos;
	while(t--) {
		ans = -1;
		for(int i = 0;i < 30;i++)
			mark[i] = 0;
		cin>>s;
		for(int i = 0;i < s.size();i++) {
			if(!mark[s[i] - 'a']) {
				pos = -1;
				mark[s[i]-'a'] = 1;
				for(int j = i+1;j < s.size();j++) {
					if(s[j] == s[i])
						pos = j;
				}
				if(pos != -1)
					ans = max(ans,pos-i-1);
			}	
		}
		printf("%d\n",ans);
	}
}
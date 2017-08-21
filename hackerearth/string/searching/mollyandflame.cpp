#include <bits/stdc++.h>
using namespace  std;
int t;
string s1,s2;
char w1[27],w2[27];
int main() {
	cin>>t;
	while(t--) {
		cin>>s1>>s2;
		for(int i = 0;i < 27;i++) {
			w1[i] = 0;
			w2[i] = 0;
		}
		int ct = s1.size() + s2.size();
		for(int i = 0;i < s1.size();i++)
			w1[s1[i]-'a']++;
		for(int i = 0;i < s2.size();i++)
			w2[s2[i]-'a']++;
		for(int i = 0;i < 27;i++) {
			if(w1[i] && w2[i])
				ct -= w1[i]+w2[i];
		}
		ct %= 5;
		ct--;
		if(ct == -1)
			ct = 4;
		string ans = "FLAME";
		ans[1] = ans[ct];
		ans[ct] = 'L';
		cout<<ans<<endl;
	}
}
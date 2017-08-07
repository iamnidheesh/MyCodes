#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n;
string s;
int m[26];
int main()
{
	cin>>t;
	while(t--) {
		cin>>s;
		memset(m,0,sizeof(m));
		for(int i = 0;i < s.size();i++) {
			m[s[i]-'a']++;
		}
		int flag = 1;
		for(int i = 0;i < 26;i++) {
			if(m[i]%2 != 0) {
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("1\n");
		else
			printf("-1\n");
	}
    return 0;
}

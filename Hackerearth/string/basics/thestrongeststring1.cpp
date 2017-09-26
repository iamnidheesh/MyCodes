#include <bits/stdc++.h>
using namespace  std;
int n;
char s[100001];
vector <char> ans;
int main()
{
	cin>>n;
	scanf("%s",s);
	char m = 'a'-1;
	char z = 'z'+1;
	int pos = 0;
	int t = 26;
	while(t--) {
		int flag = 0;
		for(int i = pos;s[i] != '\0';i++) {
			
			if(s[i] > m && s[i] < z) {
				m = s[i];
				pos = i;
				flag = 1;
			}
		}
		if(flag) {
			z = m;
			ans.push_back(m);
			m = 'a'-1;
		}
		else
			break;
	}
	for(int i = 0;i < ans.size();i++) {
		cout<<ans[i];
	}
    return 0;
}

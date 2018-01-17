#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n;
char s[2010];
int x[27][2010];
int main()
{
	cin>>n;
	scanf("%s",s);
	if(n < 4) {
		cout<<0;
		return 0;
	}
	for(int c = 0;c < 26;c++) {
		if(s[0] == 'a' + c) {
			x[c][0]++;
			break;
		}
	}
	for(int i = 1;s[i] != '\0';i++) {
		for(int c = 0;c < 26;c++) {
			if(s[i] == 'a' + c) {
				x[c][i] = 1 + x[c][i-1];
			}
			else 
				x[c][i] = x[c][i-1];
		} 
	}
	int l = strlen(s);
	long int ans = 0;
	for(int i = l-1;i >= 3;i--) {
		for(int j = 0;j < i;j++) {
			if(s[j] == s[i]) {
				for(int c = 0;c < 26;c++) {
					int corr = (s[0] == c+'a'?1:0);
					ans += (long int)(x[c][j-1]-x[c][0] + corr)*(x[c][i-1]-x[c][j]);
				}
			}
		}
	}
	cout<<ans;
    return 0;
}
	
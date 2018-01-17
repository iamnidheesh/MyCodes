#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int n;
string s[1001];
int main()
{
	cin>>n;
	for(int i = 0;i < n;i++) {
		cin>>s[i];
		int ans = 0;
		for(int j = 0;j < i;j++) {
			if(s[j] < s[i])
				ans++;
		}
		cout<<ans<<endl;
	}
    return 0;
}

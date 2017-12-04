#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100010],l[100010],ans[100010];
set <int> s;
int main() {
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for(int i = 1;i <= m;i++)
		scanf("%d",&l[i]);
	ans[n] = 1;
	s.insert(a[n]);
	for(int i = n-1;i >= 1;i--) {
		if(s.find(a[i]) == s.end()) {
			s.insert(a[i]);
			ans[i] = ans[i+1] + 1;
		}
		else {
			ans[i] = ans[i+1];
		}
	}
	for(int i = 1;i <= m;i++)
		printf("%d\n",ans[l[i]]);
}	
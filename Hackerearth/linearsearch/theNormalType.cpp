#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
long int n;
long int a[2*100001];
unordered_set <long int > s1;
int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		s1.insert(a[i]);
	}
	int d = s1.size();
	if(d == 1) {
		cout<<(n*(n+1))/2;
		return 0;
	}
	int i = 1,k,l,j;
	long int ans = 0;
	while(1) {
	    unordered_set <long int > s;
		s.insert(a[i]);
		j = i+1;
		while(j <= n) {
		   	s.insert(a[j]);
			if(s.size() == 2) {
				k = j;
				break;
			}
			j++;
		}
		bool flag = false;
		j = k;
		while(j <= n ) {
			s.insert(a[j]);
			if(s.size() == d) {
				flag = true;
				l = j;
				break;
			}
			j++;
		}
		if(flag) {
			ans += (long int)(k-i)*(n-l+1);
			
		}
		else {
			break;
		}
		i = k;
	}
	cout<<ans;
    return 0;
}

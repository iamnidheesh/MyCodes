#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n,m;
long int a[5*100001],b[5*100001];
vector <long int> v;
int main()
{
	cin>>t;
	while(t--) {
		cin>>n>>m;
		for(int i = 0;i < n;i++)
			cin>>a[i];
		for(int i = 0;i < m;i++)
			cin>>b[i];
		int p1 = 0,p2 = 0;
		while(p1 < n && p2 < m) {
			if(a[p1] > b[p2]) {
				v.push_back(a[p1]);
				p1++;
			}
			else {
				v.push_back(b[p2]);
				p2++;
			}
		}
		if(p1 == n) {
			while(p2 < m) {
				v.push_back(b[p2]);
				p2++;
			}
		}
		if(p2 == m) {
			while(p1 < n) {
				v.push_back(a[p1]);
				p1++;
			}
		}
		for(int i = 0;i < v.size();i++) {
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
    return 0;
}

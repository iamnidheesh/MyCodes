#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n,a[1000001],l;
vector <pair<int,int> > v;
bool check(int index) {
	int cmp = v[index].second;
	index = v[index].first;
	int ct = 1;
	if(l == 1)
		return true;
	for(int i = index-1;i >= 0;i--) {
		if(a[i] <= cmp) {
			cmp = a[i];
			ct++;		
			if(ct == l)
				return true;
		}
	}
	return false;
}
int main()
{
	cin>>t;
	while(t--) {
		cin>>n;
		int lo = 0,hi = n-1,mid;
		v.clear(); 
		for(int i = 0;i < n;i++) {
			cin>>a[i];
			v.push_back(make_pair(i,a[i]));
		}
		cin>>l;
		sort(v.begin(),v.end());
		while(lo < hi) {
			mid = (lo + hi)/2;
			if(check(mid)) 
				hi = mid;
			else
				lo = mid+1;
		}
		if(check(lo) && lo < n)
			cout<<v[lo].second<<endl;
		else
			cout<<-1<<endl;
	}
    return 0;
}

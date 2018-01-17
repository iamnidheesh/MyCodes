#include <bits/stdc++.h>
using namespace std;
int t,n,l,L;
pair <int,int> a[2*1001];
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>L;
		for(int i = 0;i < n;i++)
			scanf("%d%d",&a[i].first,&a[i].second);
		int l = 0,u = 0;
		sort(a,a+n);
		bool flag = false;
		while(l < n && u < n) {
			if(a[u].second - a[l].first == L) {
				flag = true;
				break;
			}
			else if(a[u].second - a[l].first > L) {
				if(u == l) {
					u++;
					l++;
				}
				else {
					l++;
				}
			}
			else {
				if(a[u+1].first <= a[u].second) {
					u++;
				}
				else {
					if(l == u) {
					    l++;
					    u++;
					}
					else
					    l++;
				}	
			}
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;	
	}
}
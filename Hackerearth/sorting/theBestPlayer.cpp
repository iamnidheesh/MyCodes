#include <bits/stdc++.h>
using namespace std;
int t,n;
pair <string,long int> p[1001];
bool cmp(pair <string,long int> x,pair <string,long int> y) {
	if(x.second > y.second)
		return true;
	else if(x.second == y.second) 
		if(x.first < y.first)
			return true;
		else return false;
	else
		return false;
}
int main() {
	cin>>n;
	cin>>t;
	for(int i = 0;i < n;i++) {
		cin>>p[i].first>>p[i].second;
	}
	sort(p,p+n,cmp);
	for(int i = 0;i < t;i++)
		cout<<p[i].first<<endl;
	
}
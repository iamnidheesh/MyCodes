#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int n;
int a[1001];
int even = 0,odd = 0;
vector <int> e,o;
int main()
{	
	cin>>n;
	for(int i = 0;i < n;i++) {
		cin>>a[i];
		if(a[i]%2 == 0) {
			e.push_back(a[i]);
			even += a[i];
		}
		else {
			o.push_back(a[i]);
			odd += a[i];
		}
	}
	sort(e.b)
	for(int i = 0;i < e.size();i++) {
		cout<<e[i]<<" ";
	}
	cout<<even<<" ";
	for(int i = 0;i < o.size();i++) {
		cout<<o[i]<<" ";
	}
	cout<<odd<<" ";

    return 0;
}

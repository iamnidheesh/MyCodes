#include <bits/stdc++.h>
using namespace std;
long int x,n,a;
int main() {
	cin>>n>>x;
	long int sum = 0;
	for(int i = 0;i < n;i++) {
		cin>>a;
		sum += a;
	}
	if(x - sum == n-1)
		cout<<"YES";
	else
		cout<<"NO";
}
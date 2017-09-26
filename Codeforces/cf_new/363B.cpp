#include <bits/stdc++.h>
using namespace std;
long int a[150001];
int n,k;
int main() {
	cin>>n>>k;
	for(int i = 1;i <= n;i++) {
		scanf("%ld",&a[i]);
	}
	for(int i = 1;i <= n;i++) {
		a[i] +=  a[i-1];
	}
	int l = 0,u = k;
	long int m = 15000000,pos = 1;
	while(u <= n) {
		if(a[u] - a[l] < m) {
			m = a[u] - a[l];
			pos = l+1;
		}
		u++;
		l++;
	}
	printf("%ld",pos);
}
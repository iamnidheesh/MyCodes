#include <bits/stdc++.h>
using namespace std;
long long int n,a[500010],l[500010],r[500010];
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	l[1] = a[1];
	for(int i = 2;i <= n;i++)
		l[i] = a[i] + l[i-1];
	r[n] = a[n] 
	for(int i = n-1;i >= 1;i--) {
		r[i] = a[i] + r[i+1];
	}
	int a = 1,b = n;
	while(a < b) {
		if(l[a] == l[b]) {
			
		}
	}
}
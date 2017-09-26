#include <bits/stdc++.h>
using namespace std;
int t,n;
long long int a[1000001],suml[1000001],sumr[1000001];
int main() {
	cin>>t;
	while(t--) {
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
			scanf("%lld",&a[i]);
		suml[0] = a[0];
		for(int i = 1;i < n;i++) {
			suml[i] = a[i] + suml[i-1];
		}
		sumr[n-1] = 2*a[n-1];
		for(int i = n-2;i >= 0;i--) {
			sumr[i] = 2*a[i] + sumr[i+1];
		}
		int r = n-1,l = 0;
		int flag = 0;
		while(l < r) {

			if(suml[l] <= sumr[r]) {
				l++;
				flag = 1;
			}
			else if(sumr[r] < suml[l]) {
				r--;
				flag = 2;
			}
		}
		if(flag == 2 )
			l++;
		else if(flag == 1)
			r--;
		else
			l++;
		if(n-1 - r < l)
			printf("%d %d\nMotu\n",l,n-1- r );
		else if(l < n-1 - r)
			printf("%d %d\nPatlu\n",l,n-1- r );
		else
			printf("%d %d\nTie\n",l,n-1-r);
	}
}
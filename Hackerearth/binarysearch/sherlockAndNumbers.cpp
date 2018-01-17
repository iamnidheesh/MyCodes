#include <bits/stdc++.h>
using namespace std;
int t;
long int n,k,p,x;
int main() {

	cin>>t;
	while(t--) {
		cin>>n>>k>>p;
		long int c = 0;
		for(int i = 0;i < k;i++) {
			scanf("%ld",&x);
			if(x <= p+c)
				c++;
		}
		if(p+c <= n)
			printf("%ld\n",p+c);
		else
			printf("-1\n");
	}
}
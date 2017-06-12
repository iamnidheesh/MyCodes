#include <bits/stdc++.h>
using namespace std;
int t;
long int n;
int main() {
	cin>>t;
	while(t--)  {
		cin>>n;
		long int m = n,count = 0;
		m = abs(m);
		while(m) {
			m = m/10;
			count++;
		}
		if(n != 0)
			count--;
		if(n >= 0)
			printf("%ld\n",(long int)pow(10,count));
		else
			printf("%ld\n",-2*n + (long int)pow(10,count));

	}
}
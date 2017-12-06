#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
	long int a[100001],b[100001],n;
	cin>>n;
	long long int x = 0;
	for(int i = 0;i < n;i++) {
		scanf("%ld",&a[i]);
		x += (long long int)a[i];
	}
	for(int i = 0;i < n;i++)
		scanf("%ld",&b[i]);
	sort(b,b+n);
	if(x <= (long long int)(b[n-1]+b[n-2]))
		cout<<"YES";
	else
		cout<<"NO";
}
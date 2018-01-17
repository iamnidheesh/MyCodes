#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n,m;
long int a[100001],x;
int main()
{
	cin>>n;
	for(int i = 0;i < n;i++) {
		scanf("%ld",&a[i]);
	}
	cin>>m;
	while(m--) {
		cin>>x;
		for(int i = 0;i < n;i++)
			if(a[i] > x) a[i]--;
	}
	for(int i = 0;i < n;i++)
		printf("%ld ",a[i]);
    return 0;
}

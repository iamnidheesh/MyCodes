#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
long int n,a[2*5*10001];
int main()
{
	cin>>n;
	for(int i = 0;i < 2*n;i++)
		cin>>a[i];
	sort(a,a+2*n);
	long int sum = 0;
	for(int i = 0;i < 2*n;i+=2)
		sum += a[i];
	cout<<sum;
    return 0;
}

#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int n;
li a[100001],x;
int main()
{
	cin>>n>>x;
	int ans = 0,skip = 0,flag = 1;
	for(int i = 0;i < n;i++) {
		scanf("%ld",&a[i]);
		if(a[i] <= x && flag) 
			ans++;
		else
			skip++;
		if(skip > 1)
			flag = 0;

	}
	printf("%d",ans) ;
    return 0;
}

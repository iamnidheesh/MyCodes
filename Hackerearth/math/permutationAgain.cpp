#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t;
int main()
{
	cin>>t;
	li n;
	while(t--) {
		cin>>n;
		if(n == 1)
	        printf("1\n");
	    else
		    printf("%ld\n",(n*n)/2 -1);

	}
    return 0;
}

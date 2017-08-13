#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t;
int Len,U[1000001],L[1000001];
int main()
{
	cin>>t;
	while(t--) {
		cin>>Len;
		int ans = Len;
		for(int i = 1;i <= Len-1;i++) {
			scanf("%d",&U[i]);
			U[i] += i;
			ans = max(U[i],ans);
		}
		for(int i = 1;i <= Len-1;i++) {
			scanf("%d",&L[i]);
			L[i] += i;
			ans = max(L[i],ans);
		}
		printf("%d\n",ans);
	}
    return 0;
}

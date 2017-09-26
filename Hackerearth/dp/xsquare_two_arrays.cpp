#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int N,Q,T,L,R;
lli A[100001],B[100001];
lli sb[100001],sa[100001];
int main()
{
	cin>>N>>Q;
	for(int i = 1;i <= N;i++) { 
		scanf("%lld",&A[i]);
	}
	for(int i = 1;i <= N;i++)
		scanf("%lld",&B[i]);

	sa[1] = A[1],sa[2] = A[2],sb[1] = B[1],sb[2] = B[2];
	
	for(int i = 3;i <= N;i++) {
		sa[i] += A[i] + sa[i-2];
		sb[i] += B[i] + sb[i-2];
	}
	while(Q--) {
		scanf("%d%d%d",&T,&L,&R);
		if(T == 1) {
			if((R-L)%2 == 0)
				printf("%lld\n",sa[R] - sa[L] + A[L] + sb[R-1] - sb[L+1] + B[L+1]);
			else
				printf("%lld\n",sb[R] - sb[L+1] + B[L+1] + sa[R-1] - sa[L] + A[L]);
		}
		else {
			if((R-L)%2 == 0)
				printf("%lld\n",sb[R] - sb[L] + B[L] + sa[R-1] - sa[L+1] + A[L+1]);
			else
				printf("%lld\n",sa[R] - sa[L+1] + A[L+1] + sb[R-1] - sb[L] + B[L]);
		}
	}
    return 0;
}

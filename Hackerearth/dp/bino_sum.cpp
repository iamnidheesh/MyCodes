#include <bits/stdc++.h>
using namespace std;
#define MOD  1000000007
#define lli long long int
lli fact[1001];
lli t,p,n;
lli modInverse(lli a, lli m)
{
    lli m0 = m, t, q;
    lli x0 = 0, x1 = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
    {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}
lli C(lli k,lli r) {
	lli b = (fact[r]*fact[k-r])%MOD;
	return (fact[k]*((modInverse(b,MOD))%MOD))%MOD;
}
int main() {
	cin>>t;
	memset(fact,1,sizeof(fact));
	fact[0] = 1;
	for(lli  i = 1;i <= 1000;i++) {
		fact[i] = fact[i-1]*i;
		fact[i] %= MOD;
	}
	while(t--) {
		cin>>n>>p;
		lli sum = 0;
		for(lli i = 0;i <= p;i++) {
			sum += C(n,i);
			sum %= MOD;
		}
		printf("%lld\n",sum);
	}
}
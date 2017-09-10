#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
llu gcd(llu a,llu b) {
    return b == 0 ? a :gcd(b,a%b);
}
int main() {
    llu n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    llu  cp = n/a;
    llu cq= n/b;
    llu cpq =n/((a*b)/gcd(a,b));
    llu  mpq = max(p,q);
    cout<<(cp - cpq)*p + (cq - cpq)*q + cpq*mpq;
    return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
#define llu unsigned long long int
llu gcd(llu a,llu b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int main() {

    llu a,b,c;
    int t;
    cin>>t;
    while(t--) {
        scanf("%llu%llu",&a,&b);
        c = gcd(a,b);
        printf("%llu %llu\n",b/c,a/c);
    }

}

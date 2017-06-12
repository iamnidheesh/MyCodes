#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
llu gcd ( llu a, llu b )
{
  llu c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
int main()  {
    llu n,k,ans,l,u,b,a,g;
    while(1) {
        cin>>n>>k;
        a = 0;
        b = (n*(n-1))/2;
        l = 1;
        u = k-1;
        if(k == -1)
            break;
        while(l < u) {
            a = a + u - l;
            l++;
            u--;
        }
        if(a == 0)
            printf("%d\n",0);
        else if (a == b)
            printf("%d\n",1);
        else {
            g = gcd(a,b);
            printf("%llu%c%llu\n",a/g,'/',b/g);
        }
    }
}

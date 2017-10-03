#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int n,m;
lli a[100010],l;
int main()
{
    cin>>n>>l>>m;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%lld",&a[i]);
        if(a[i] > l)
            a[i] = 0;
        else
            a[i] = 1;
    }
    for(int i = 2;i <= n;i++)
        a[i] += a[i-1];
    for(int i = 1;i <= n-m+1;i++) {
        if(a[i+m-1] - a[i-1] == m)
            ans++;
    }
    cout<<ans;
    return 0;
}

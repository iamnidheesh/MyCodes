#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
int main() {
    int t;
    llu n,k,m,ans;
    cin>>t;
    while(t--) {
        ans = 0;
        cin>>n>>k>>m;
        while(n <= m/k) {
            m = m/k;
            ans++;
        }
        printf("%llu\n",ans);
    }
}

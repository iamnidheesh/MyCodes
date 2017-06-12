#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector < ll > j,k,x;
ll xi;
int main() {
    ll n;
    cin>>n;
    for(ll i = 0;i < n;i++) {
        scanf("%lld",&xi);
        x.push_back(xi);
    }
    for(vector < ll > :: iterator a = x.begin();a != x.end();a++)
        for(vector < ll > :: iterator b = x.begin(); b != x.end();b++)
            for(vector < ll > :: iterator c = x.begin();c != x.end();c++) {
                j.push_back((*a)*(*b) + *c);
                if(*a != 0) {
                    k.push_back((*a)*(*b + *c));
                }
            }
    sort(k.begin(),k.end());
    sort(j.begin(),j.end());
    ll ans = 0;
    for(vector < ll > :: iterator i = j.begin();i != j.end();i++) {
            ans = ans - (lower_bound(k.begin(),k.end(),*i) - upper_bound(k.begin(),k.end(),*i));
    }
    cout<<ans;
}

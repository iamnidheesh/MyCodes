#include<bits/stdc++.h>
using namespace std;
#define ll int
vector < ll > j,k,a,b,c,d;
int main() {
    int n;
    ll p,q,r,s;
    cin>>n;
    for(int i = 0;i < n;i++) {
        scanf("%d%d%d%d",&p,&q,&r,&s);
        a.push_back(p);
        b.push_back(q);
        c.push_back(r);
        d.push_back(s);
    }
    for(vector < ll > :: iterator i = a.begin();i != a.end();i++)
        for(vector < ll > :: iterator x = b.begin();x != b.end();x++)
            j.push_back(*i + *x);
     for(vector < ll > :: iterator i = c.begin();i != c.end();i++)
        for(vector < ll > :: iterator x = d.begin();x != d.end();x++)
            k.push_back(-1*(*i + *x));
    sort(j.begin(),j.end());
    sort(k.begin(),k.end());
    ll ans = 0;
    for(vector < ll > :: iterator i = j.begin();i != j.end();i++) {
        pair <vector <int> :: iterator,vector <int> :: iterator> p =  equal_range(k.begin(),k.end(),*i);
        ans = ans + p.second - p.first;
    }
    cout<<ans;
}

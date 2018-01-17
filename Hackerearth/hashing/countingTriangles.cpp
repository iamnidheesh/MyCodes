#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int n;
long long int x,y,z,k;
int main()
{
    cin>>n;
    map <long long int,int> m;
    while(n--) {
        cin>>x>>y>>z;
        vector <long long int> v;
        v.push_back(x);v.push_back(y);v.push_back(z);
        sort(v.begin(),v.end());
        k = 0;
        k += v[0]*11;
        k += v[1]*111;
        k += v[2]*1111;
        k += 1e15+1111;
        m[k]++;
    }
    int ans = 0;
    for(map <long long int,int > :: iterator it = m.begin();it != m.end();it++ ) {
        if(it->second == 1)
            ans++;
    }
    cout<<ans;
    return 0;
}

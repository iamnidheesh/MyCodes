#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
set <string> ct;
string s;
int t,n,m;
int main()
{
    cin>>t;
    while(t--) {
        cin>>n>>m;
        ct.clear();
        for(int i = 0;i < n;i++) {
            cin>>s;
            ct.insert(s);
        }
        if(ct.size() == n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

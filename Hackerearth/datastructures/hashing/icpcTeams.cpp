#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n,k;
string s[1001];
vector <int> v;
int main()
{
    cin>>t;
    while(t--) {
        cin>>n>>k;
        v.clear();
        for(int i = 0;i < n;i++)
            cin>>s[i],v.push_back(s[i].size());
        sort(v.begin(),v.end());
        bool flag = true;
        for(int i = 0;i < n; i+= k) {
            if(v[i] != v[i+k-1]) {
                flag = false;break;
            }
        }
        if(flag)
            cout<<"Possible"<<endl;
        else
            cout<<"Not possible"<<endl;
    }
    return 0;
}

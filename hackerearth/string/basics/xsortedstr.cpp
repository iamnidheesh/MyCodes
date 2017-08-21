#include <bits/stdc++.h>
using namespace  std;
int t,n,k,m;
pair <string,int> s[1001];
string c[1001];
char temp[1001]; 
int main()
{
    cin>>t;
    while(t--) {
        cin>>n>>k>>m;
        for(int i = 0;i < n;i++) {
            scanf("%s",temp);
            s[i].second = i;
            c[i] = (string)temp;
            s[i].first = ((string)temp).substr(0,m);
        }
        sort(s,s+n);
        cout<<c[s[k-1].second]<<endl;
    }
    return 0;
}

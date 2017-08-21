#include <bits/stdc++.h>
using namespace  std;
int t;
string s;
int main()
{
    cin>>t;
    int flag;
    while(t--) {
        cin>>s;
        flag = 1;
        for(int i = 0;i < s.size()-1;i++) {
            if(abs(s[i+1]-s[i]) == 1 || abs(s[i+1]-s[i]) == 25 )
                continue;
            else {
                flag = 0;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

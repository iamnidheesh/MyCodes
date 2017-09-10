#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    int n;
    cin>>n;
    int flag = 0;
    while(n--) {
        string s;
        int rb,ra;
        cin>>s;
        cin>>rb>>ra;
        if(rb >= 2400 && ra > rb)
            flag = 1;
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
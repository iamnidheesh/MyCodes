#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n;
    cin>>n;
    int flag = 0;
    for(int a = 0;a < 1000;a++) {
        for(int b = 0; b < 100 ;b++)
            if((n - (a*1234567 + b*123456))%1234 == 0 && (n - (a*1234567 + b*123456)) >= 0) {
                flag = 1;
            //    cout<<n - (a*1234567 + b*123456)<<endl;
              //  cout<<flag<<endl;
                break;
            }
        if(flag)
            break;
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
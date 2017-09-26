#include<bits/stdc++.h>
using namespace std;
int main() {
    long int a,n,t,c,b = 0,k = 0;
    cin>>n>>t>>c;
    for(long int  i = 0;i < n;i++) {

        cin>>a;
        if(a <= t)
            b++;
        else
            b = 0;
        if(b >= c)
            k++;
    }
    cout<<k;
}
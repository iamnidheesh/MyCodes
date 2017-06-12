#include<bits/stdc++.h>
using namespace std;
int main() {
    long int  n,k;
    cin>>n>>k;
    long int  ans = 0;
    long int i = 1;
    while(ans <= n) {
        ans = k*i;
        i++;
    }
    cout<<ans;
    return 0;
}
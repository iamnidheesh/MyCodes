#include<bits/stdc++.h>
using namespace std;
int main() {
    long long int a[100001],n,x,s=0;
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        s=s+x*a[i];
        if(x!=1)
            x--;
    }
    cout<<s;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
#define ll long long int;
llu a[100001],c;
int main() {
    int n;
    cin>>n;
    for(int i = 0;i < n;i++) {
        cin>>a[i];
        if(a[i] != 1)
            c = c + a[i] -1;
        if(c % 2== 0)
            cout<<2<<endl;
        else
            cout<<1<<endl;
    }


}
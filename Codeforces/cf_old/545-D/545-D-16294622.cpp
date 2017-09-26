#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long int a[100000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long int s=a[0];
    int c=1;
    for(int i=1;i<n;i++) {
        if(s<=a[i]) {
            s=s+a[i];
            c++;
        }
        }
    cout<<c;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long int a[100001];
int main() {
    long int t;
    int n,c = 0,m = 0;
    cin>>n>>t;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    long int l = 0;
    long int u = 0,s = 0;
    while(u != n) {
        if(s + a[u] > t) {
            if(l == u) {
                l++;
                u++;
                s = 0;
                c = 0;
            }
            else {
            s = s - a[l];
            l++;
            c--;
            }
        }
        else {
            s = s + a[u];
            u++;
            c++;
        }
        m = max(c,m);
    }
    cout<<m;
}
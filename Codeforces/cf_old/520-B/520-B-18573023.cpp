#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,c = 0;
    cin>>n>>m;
    while(m != n) {
        if(m%2 == 0 && m > n) {
            m = m/2;
        }
        else {
            m = m + 1;
        }
        c++;
    }
    cout<<c;
    return 0;
}
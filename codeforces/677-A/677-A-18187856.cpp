#include<bits/stdc++.h>
using namespace std;
#define llu long long unsigned int
int main() {
    int n;
    int h;
    int h1;
    int s = 0;
    cin>>n>>h;
    while(n--) {
    cin>>h1;
    if(h1 > h)
        s = s + 2;
    else
        s = s + 1;
    }
    cout<<s;
















    return 0;
}
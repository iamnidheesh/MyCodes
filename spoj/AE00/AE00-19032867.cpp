#include<bits/stdc++.h>
using namespace std;
int n;
int find_sq(int x) {
    int r = 0;
    for(int i = 1;i*i <= x;i++) {
        if(x%i == 0)
            r++;
    }
    return r;
}
int main() {
    int ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        ans = ans + find_sq(i);
    }
    cout<<ans;
}

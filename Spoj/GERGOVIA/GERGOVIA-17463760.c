#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while(1) {
        cin>>n;
        if(n == 0)
            break;
        long long int a,s;
        long long int ans = 0;
        cin>>a;
        s = a;
        for(int i = 1;i < n;i++) {
            cin>>a;
            ans = ans + abs(s);
            s = a + s;
        }
        cout<<ans<<endl;
    }


}

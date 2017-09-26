#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
int c[101];
int d[101];
int main() {
    int n,a;
    cin>>n>>a;
    for(int i = 1;i <= n;i++)
        cin>>c[i];
    int dis = max(a -1,n-a);
    for(int i = 1;i <= n;i++)
     {
        d[abs(a - i)]  += c[i];
    }
     int s = 0;
    for(int i = 0;i <= dis;i++) {

        if( a + i <= n && a- i >0 && d[i] == 1);
        else
            s = s + d[i];
    }
    cout<<s + d[0];
    return 0;
}
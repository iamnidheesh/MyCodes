#include<bits/stdc++.h>
using namespace std;
int a[1001];
int n,k,s;
int main() {

    cin>>n>>k>>s;
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    int tt = s*k;
    int ans = 0,sum = 0;
    sort(a,a+n,greater <int> ());
    for(int i = 0;i < n;i++) {
        sum = sum + a[i];
        ans++;
        if(sum >= tt)
            break;
    }
    cout<<ans;
}

#include<bits/stdc++.h>
using namespace std;
long int a[10001];
int t,n;
int main() {
    cin>>t;
    while(t--) {
       cin>>n;
       int flag = 1;
       for(int i = 0;i < n;i++)
        scanf("%ld",&a[i]);
       for(int i = 0;i < n-1;i++) {
        a[i+1] -= a[i];
        a[i] = 0;
        if(a[i+1] < 0) {
            flag = 0;
            break;
        }
       }
       if(a[n-1] != 0)
        flag = 0;
       if(flag)
        printf("YES\n");
       else
        printf("NO\n");
    }
}

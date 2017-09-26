#include<bits/stdc++.h>
using namespace std;
long long int alt[5010],a[5010],m;
int main() {
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
        scanf("%lld",&a[i]);
    for(int i = 0;i < n;i++)
        alt[i] = 1;
    for(int i = 1;i < n;i++)
        for(int j = 0;j < i;j++) {
            if(a[i]*a[j] < 0 && abs(a[i]) > abs(a[j]) && alt[i] < alt[j]+1)
                alt[i] = alt[j] + 1;
    }
    m = INT_MIN;
    for(int i = 0;i < n;i++) {
        if(m < alt[i])
            m = alt[i];
    }
    printf("%lld",m);
}

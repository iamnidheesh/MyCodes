#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[1001];
int main() {

    cin>>n>>m;
    for(int i = 0;i < m;i++)
        scanf("%d",&f[i]);
    sort(f,f+m);
    int ans = 100000;
    for(int i = 0;i < m-n+1; i++)
        if((f[i+ n-1] - f[i]) < ans)
           ans = f[i + n-1] - f[i];
    printf("%d",ans);
}
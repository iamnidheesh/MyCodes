#include<bits/stdc++.h>
using namespace std;
int n;
int a[110];
int cnt[110];
int main() {
    cin>>n;
    int ans = 0;
    int mval;
    for(int i = 1;i <= n;i++)
        cin>>a[i];
    cnt[1] = a[1];
    for(int i = 1;i <= n;i++) {
        cnt[i] = a[i] + cnt[i-1];
    }
    mval = cnt[n];
    for(int i = 1;i <= n;i++)
        for(int j = i;j <= n;j++) {
            ans = max(ans,cnt[n] + (j - i + 1) - 2*(cnt[j]-cnt[i-1]) );
        }
    printf("%d",ans);
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300001];
int main() {
    cin>>n>>m;
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    int p = 0,q = 0;
    int ans = 0,sum = 0;
    while(q < n && p < n) {
            if(sum + a[q] <= m) {
                sum = sum + a[q];
                q++;
            }
            else {
                sum = sum-a[p];
                p++;
            }
            ans = max(ans,sum);
    }
    printf("%d",ans);
}

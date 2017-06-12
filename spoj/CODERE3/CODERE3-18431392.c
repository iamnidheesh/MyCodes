#include<bits/stdc++.h>
using namespace std;
//O ( N ^ 2 ) solution
int lds[1010],lis[1010],a[1010];
int t,ans,n;
int main() {
    cin>>t;
    while(t--) {
        scanf("%d",&n);
        ans = 0;
        for(int i = 0;i < n;i++) {
            scanf("%d",&a[i]);
            lds[i] = 1;
            lis[i] = 1;
        }
        // longest increasing subsequence ...
        for(int i = 1;i < n;i++)
            for(int j = 0;j < i;j++)
                if(a[i] > a[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        //longest decreasing subsequence ...
        for(int i = n-2;i >= 0;i--)
            for(int j = n - 1;j > i;j--)
                if(a[i] > a[j] && lds[i] < lds[j] + 1)
                    lds[i] = lds[j] + 1;
        for(int i = 0;i < n;i++) {
            ans = max(ans,lds[i] + lis[i] - 1);
        }
        printf("%d\n",ans);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t,n,a[21],dp[21][2000];
set <int> s;
void cal(int k,int sum) {
    if(k >= n){
        s.insert(sum);
        return;
    }
    if(dp[k][sum] == 1)
        return ;
    cal(k+1,sum);
    cal(k+1,sum + a[k]);
    dp[k][sum] = 1;
    return; 
}
int main()
{
    cin>>t;
    while(t--) {
        cin>>n;
        s.clear();
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i < n;i++) {
            cin>>a[i];
        }
        cal(0,0);
        printf("%lu\n",s.size());
    }
    return 0;
}

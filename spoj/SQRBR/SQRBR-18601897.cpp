#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int a[100];
long int dp[25][25];
long int cal(int s,int e) {

    if(s > n)
        return 0;
    if(s == n) {
        if(e == n)
            return 1;
    }
    if(s > n)
        return 0;
    if(e > s)
        return 0;
    if(dp[s][e] != -1)
        return dp[s][e];
    int flag = 0;
    for(int i = 0;i < k;i++)
        if(a[i]-1 == e+s) {
                flag = 1;
                break;
        }
    //int z = cal(s+1,e);
  //  int x = cal(s,e+1);
    if(flag) {
        dp[s][e] = cal(s+1,e);
    }
    else {
            dp[s][e] = (cal(s+1,e) + cal(s,e+1));
    }
    return dp[s][e];
}
int main() {
    cin>>t;
    while(t--) {
        scanf("%d%d",&n,&k);
        for(int i = 0;i < k;i++)
            scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        if(n == 0)
            printf("0\n");
        else
            printf("%ld\n",cal(0,0));
    }
}

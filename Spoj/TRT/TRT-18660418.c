#include<bits/stdc++.h>
using namespace std;
long int dp[2010][2010];
int n;
long int a[2010];
long  cal(int i,int j) {
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = max(a[i]*(n-(j-i))+cal(i+1,j),a[j]*(n-(j-i))+cal(i,j-1));
}
int main() {
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i < n;i++)
        scanf("%ld",a+i);
    printf("%ld\n",cal(0,n-1));
}

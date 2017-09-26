#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long int turns[10][4] = { {7} , {2,4} , {1,3,5} , {2,6} , {1,5,7} ,
                     {2,4,6,8} , {3,5,9} , {0,4,8} , {5,7,9} , {6,8}};
long int choice[10] = {1,2,3,2,3,4,3,3,3,2};
long int dp[10][100010];
int n;
long int cal(int c,int x) {

    if(x == 1)
        return 1;
    if(dp[c][x] != -1)
        return dp[c][x];
    long int sum = 0;
    for(int i = 0;i < choice[c];i++) {
        sum = sum + cal(turns[c][i],x-1);
        sum = sum%MOD;
    }
   // sum = sum*choice[c];
    return dp[c][x] = sum;
}
int main() {

    int t;
    long int sum = 0;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    while(t--) {
        scanf("%d",&n);
        sum = 0;
     //   memset(dp,-1,sizeof(dp));
        for(int i = 0;i < 10;i++) {
            sum = sum +  cal(i,n);
            sum = sum%MOD;
        }
        printf("%ld\n",sum);
    }
}

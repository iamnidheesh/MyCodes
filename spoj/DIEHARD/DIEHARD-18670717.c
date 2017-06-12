#include<bits/stdc++.h>
using namespace std;
int t,x,y;
int dp[1010][1010][3];
int cal(int h,int a,int d) {

    if(h <= 0 || a <= 0)
        return -1;
    if(dp[h][a][d] != -1)
        return dp[h][a][d];
    if(d == 0)
        return dp[h][a][d] = 1 + max(cal(h-5,a-10,1),cal(h-20,a+5,2));
    else if(d == 1)
        return dp[h][a][d] = 1 + max(cal(h+3,a+2,0),cal(h-20,a+5,2));
    else
        return dp[h][a][d] = 1 + max(cal(h+3,a+2,0),cal(h-5,a-10,1));

}
int main() {
    cin>>t;
    while(t--) {
         memset(dp,-1,sizeof(dp));
        scanf("%d%d",&x,&y);
        printf("%d\n",max(cal(x,y,0),max(cal(x,y,1),cal(x,y,2))));

    }
}

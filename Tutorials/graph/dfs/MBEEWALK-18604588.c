#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int t;
int n;
int ox = 15;
int oy = 15;
ll dp[32][32][15];
ll cal(int x,int y,int steps) {

    if(steps == n) {
        if(x == ox && y == oy)
            return 1;
        else
            return 0;
    }
    if(steps > n)
        return 0;
    if(dp[x][y][steps] != -1)
        return dp[x][y][steps];
    int p1 = cal(x+1,y,steps+1);
    int p2 = cal(x,y+1,steps+1);
    int p3 = cal(x-1,y,steps+1);
    int p4 = cal(x,y-1,steps+1);
    int p5 = cal(x-1,y+1,steps+1);
    int p6 = cal(x+1,y-1,steps+1);
    return dp[x][y][steps] = p1+p2+p3+p4+p5+p6;
}
int main() {
    cin>>t;
    while(t--) {
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        printf("%llu\n",cal(15,15,0));
    }

}

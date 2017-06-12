
#include<bits/stdc++.h>
using namespace std;
int t,m,n;
char a[205][205];
int dp[205][205];
int cal(int i,int j,int c) {
    if(dp[i][j] != -1)
        return dp[i][j];
    int k = 0,l = 0;
    if(c == 1) {
        if(i != m-1 && a[i+1][j] != '#') {
            k = cal(i+1,j,0);
        }
        if(j != n-1 && a[i][j+1] != '#') {
            l = cal(i,j+1,1);
        }
    }
    else {
         if(i != m-1 && a[i+1][j] != '#') {
            k = cal(i+1,j,1);
        }
        if(j != 0 && a[i][j-1] != '#') {
            l = cal(i,j-1,0);
        }
    }
    return dp[i][j] = max(k,l) +  ( (a[i][j] == 'T') ? 1 : 0);
}
int main() {

    cin>>t;
    while(t--) {
        memset(dp,-1,sizeof(dp));
        cin>>m>>n;
        for(int i = 0;i < m;i++)
            scanf("%s",a[i]);
        if(a[0][0] == '#') {
            printf("0\n");
            continue;
        }
        printf("%d\n",cal(0,0,1));
    }

}

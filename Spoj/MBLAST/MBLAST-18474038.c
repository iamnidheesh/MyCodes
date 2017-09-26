#include<bits/stdc++.h>
using namespace std;
int dp[2010][2010];
int k;
char s1[2010],s2[2010];
int n1,n2;
int cal(int x1,int x2) {
    if(x1 == n1 && x2 == n2)
        return 0;
    else if(x2 == n2)
        return k*(n1-x1);
    else if(x1 == n1)
        return k*(n2-x2);

    if(dp[x1][x2] != -1)
        return dp[x1][x2];
    return dp[x1][x2] = min(min(k + cal(x1+1,x2),k + cal(x1,x2+1)),
                            abs(s1[x1]-s2[x2]) + cal(x1+1,x2+1));

}
int main() {
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%d",&k);
        n1 = strlen(s1);
        n2 = strlen(s2);
        memset(dp,-1,sizeof(dp));
        printf("%d",cal(0,0));
        return 0;
}

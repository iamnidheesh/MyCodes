#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int k,n1,n2;
char s1[1010];
char s2[1010];
int cal(int x1,int x2) {
    if(x1 == n1 || x2 == n2)
        return 0;
    if(dp[x1][x2] != -1)
        return dp[x1][x2];
    int cs = 0;
    int j1 = x1;
    int j2 = x2;
    int m = INT_MIN;
    while(1) {
        if(j1 == n1 || j2 == n2)
            break;
        if(s1[j1] == s2[j2]) {
            cs++;
            j1++;
            j2++;
        }
        else
            break;
        if(cs >= k)
            m = max(m,cs + cal(x1+cs,x2+cs));
    }
    dp[x1][x2] = max(m,max(cal(x1,x2+1),cal(x1+1,x2)));
    return dp[x1][x2];
}
int main() {
    while(1) {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&k);
        if(k == 0)
            break;
        scanf("%s",s1);
        scanf("%s",s2);
        n1 = strlen(s1);
        n2 = strlen(s2);
        printf("%d\n",cal(0,0));
    }
    return 0;
}

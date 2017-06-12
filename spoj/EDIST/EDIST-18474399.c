#include<bits/stdc++.h>
using namespace std;
int dp[2010][2010];
int t,n1,n2;
char s1[2010],s2[2010];
int cal(int x1,int x2) {
   if(x1 == n1 && x2 == n2)
        return 0;
   else if(x1 == n1)
        return n2 - x2;
   else if(x2 == n2)
        return n1 - x1;
   if(dp[x1][x2] != -1)
        return dp[x1][x2];
   return dp[x1][x2] = s1[x1] == s2[x2] ? cal(x1+1,x2+1):
          1 + min(min(cal(x1+1,x2),cal(x1,x2+1)),cal(x1+1,x2+1));

}
int main() {
    cin>>t;
    while(t--) {
        memset(dp,-1,sizeof(dp));
        scanf("%s",s1);
        scanf("%s",s2);
        n1 = strlen(s1);
        n2 = strlen(s2);
        printf("%d\n",cal(0,0));
    }
    return 0;
}

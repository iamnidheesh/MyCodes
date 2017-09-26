#include<bits/stdc++.h>
using namespace std;
char s[30];
int dp[30][256],vis[30][256],n,c,ans;
int cal(int idx,int sum) {
    if(idx == n)
        return 1;
    if(vis[idx][sum] == c) return dp[idx][sum];
    vis[idx][sum] = c;
    dp[idx][sum] = 0;

    int gsum = 0;
    for(int i = idx;i < n;i++) {
        gsum +=  s[i];
        if(gsum >= sum)
            dp[idx][sum] += cal(i+1,gsum);
    }
   // ans = ans + dp[idx][sum];
    return dp[idx][sum];
}
int main() {
    c = 0;
    while(1) {
        scanf("%s",s);
        if(strcmp(s,"bye") == 0)
            return 0;
        c++;
        n = strlen(s);
        for(int i = 0;s[i] != '\0';i++)
            s[i] -= '0';
        //ans = 0;
        printf("%d. %d\n",c,cal(0,0));
    }
}

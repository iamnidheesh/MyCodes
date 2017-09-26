#include <bits/stdc++.h>
using namespace std;
int t;
char s[1000001];
int dp[1000001];
bool checkdiff(char x,char y,char z) {
    if(x == y && y == z)
        return false;
    else
        return true;
}
int main() {
    cin>>t;
    while(t--) {
        scanf("%s",s);
        int ans = 0;
        dp[0] = 0,dp[1] = 0;
        if(strlen(s) > 2) {
            if(checkdiff(s[0],s[1],s[2])) {
                dp[2] = 1;
            }
            else
                dp[2] = 0;
        }
        for(int i = 3;s[i] != '\0';i++) {
            if(checkdiff(s[i],s[i-1],s[i-2])) {
                if(dp[i-3] > 0)
                    dp[i] = 1 + dp[i-3];
                else
                    dp[i] = 1;
            }
            else
                dp[i] = 0;
            ans = max(ans,dp[i]);
        }
        printf("%d\n",strlen(s)-3*ans);
    }
}
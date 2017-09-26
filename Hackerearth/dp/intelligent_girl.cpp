#include <bits/stdc++.h>
using namespace std;
char s[10100];
int dp[10100];
int main() {

	scanf("%s",s);
	for(int i = 0;s[i] != '\0' ;i++) {
		if((s[i]-'0') % 2 == 0)
			dp[0]++;
	}
	printf("%d ",dp[0]);
	for(int i = 1;s[i] != '\0'; i++) {
		if( (s[i-1] - '0') % 2 == 0 )
			dp[i] = dp[i-1] - 1;
		else
			dp[i] = dp[i-1]; 
		printf("%d ",dp[i]);
	}

}
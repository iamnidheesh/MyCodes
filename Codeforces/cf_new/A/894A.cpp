#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
char s[101];
int pre[101],post[101];
int main() {
	scanf("%s",s);
	int l = strlen(s);
	int preCount = 0,postCount = 0;
	for(int i = 0;i < l;i++) {
		if(s[i] == 'Q')
			preCount++;
		if(s[i] == 'A')
			pre[i] = preCount;
	}
	for(int i = l-1;i >= 0;i--) {
		if(s[i] == 'Q')
			postCount++;
		if(s[i] == 'A')
			post[i] = postCount;
	}
	int ans = 0;
	for(int i = 0;i < l;i++) {
		if(s[i] == 'A') {
			ans += pre[i]*post[i];
		}
	}
	cout<<ans;
}
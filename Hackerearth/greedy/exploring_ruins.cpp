#include <bits/stdc++.h>
using namespace std;
char s[100];
int main() {
	scanf("%s",s+1);
	for(int i = 1;s[i] != '\0';i++) {
		if(s[i] == '?') {
			if(s[i-1] == 'a' || s[i+1] == 'a')
				s[i] = 'b';
			else
				s[i] = 'a';
		}
	}
	printf("%s",s+1);
}
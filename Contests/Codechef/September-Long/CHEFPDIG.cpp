#include <bits/stdc++.h>
using namespace std;
int t;
char s[100001];
map <int,int> m;
int main() {
	cin>>t;
	while(t--) {
		scanf("%s",s);
		m.clear();
		for(int i = 0; s[i] != '\0';i++)
			m[s[i]-'0']++;
		for(int i = 'A';i <= 'Z';i++) {
			if(i%10 == (i/10)%10) {
				if(m[i%10] >= 2)
					printf("%c",i);
			}
			else if(m[i%10] > 0 && m[(i/10)%10] > 0)
				printf("%c",i);
		}
		printf("\n");
	}
}
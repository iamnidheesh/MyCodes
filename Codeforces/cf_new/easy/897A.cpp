#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n,m,l,r;
	char c1,c2;
	char s[103];
	cin>>n>>m;
	scanf("%s",s+1);
	while(m--) {
		cin>>l>>r>>c1>>c2;
		for(int i = l;i <= r;i++)
			if(s[i] == c1)
				s[i] = c2;
	}
	printf("%s",s+1);
}
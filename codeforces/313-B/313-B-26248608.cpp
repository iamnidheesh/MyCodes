#include <bits/stdc++.h>
using namespace std;
char s[100005];
int precmp[100002];
int m,l,r;
int main() {

	scanf("%s",s);
	cin>>m;
	for(int i = 1;s[i] != '\0';i++) {
		if(s[i] == s[i-1])
			precmp[i] = precmp[i-1] + 1; 
		else
			precmp[i] = precmp[i-1];
	}
	while(m--) {
		scanf("%d%d",&l,&r);
		printf("%d\n",precmp[r-1]-precmp[l-1]);
	}
}
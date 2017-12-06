#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
char s[110];
int main() {
	int L = 0,U = 0,R = 0,D = 0;
	cin>>n;
	scanf("%s",s);
	for(int i  = 0; s[i] != '\0';i++) {
		if(s[i] == 'L')
			L++;
		if(s[i] == 'U')
			U++;
		if(s[i] == 'R')
			R++;
		if(s[i] == 'D')
			D++;
	}
	cout<<2*min(L,R) + 2*min(D,U);
}
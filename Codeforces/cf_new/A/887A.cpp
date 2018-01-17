#include <bits/stdc++.h>
using namespace std;
char s[102];
int main() {
	scanf("%s",s);
	int l = strlen(s)-1;
	int val = 0;
	bool flag = false;
	char cmp[8] = "0000001";
	int k = 0;
	for(int i = l;i >= 0;i--) {
		if(s[i] == cmp[k])
			k++;
		if(k == 7){
			flag = true;
			break;
		}
	}
	if(flag)
		cout<<"yes";
	else
		cout<<"no";
}
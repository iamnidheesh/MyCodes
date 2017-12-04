#include <bits/stdc++.h>
using namespace std;
char s[101];
int main() {
	scanf("%s",s);
	bool flag = false;
	int n = strlen(s),num;

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < i;j++) {
			for(int k = 0;k < j;k++) {
				num = (s[i] - '0') + (s[j] - '0')*10 + (s[k] - '0')*100;
				if(num%8 == 0) {
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			break;
	}
	if(!flag) {
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < i;j++) {
				num = (s[i] - '0') + (s[j] - '0')*10;
				if(num%8 == 0) {
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	if(!flag) {
		for(int i = 0;i < n;i++) {
			num = (s[i] - '0');
			if(num%8 == 0) {
				flag = true;
				break;
			}
		}
	}
	
	if(flag) {
		cout<<"YES"<<endl;
		cout<<num;
	}
	else {
		cout<<"NO"<<endl;
	}

}
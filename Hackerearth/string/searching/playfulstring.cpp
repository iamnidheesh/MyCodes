#include <bits/stdc++.h>
using namespace  std;
int t;
string p,s;
int main() {
	
	cin>>t;
	while(t--) {
		cin>>s>>p;
		int j = 0;
		int flag;
		for(int i = 0;i < p.size();i++) {
			flag = 0;
			while(j < s.size()) {
				if(p[i] == s[j]) {
					j++;
					flag = 1;
					break;
				}
				j++;
			}
			if(!flag) {
				break;
			}
		}
		j = 0;
		if(flag)
			for(int i = p.size()-1;i >= 0;i--) {
				flag = 0;
				while(j < s.size()) {
					if(p[i] == s[j]) {
						j++;
						flag = 1;
						break;
					}
					j++;
				}
				if(!flag) {
					break;
				}
			}
		if(!flag) 
			printf("BAD STRING\n");
		else
			printf("GOOD STRING\n");
	}
}
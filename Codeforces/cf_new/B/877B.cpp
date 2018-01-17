#include <bits/stdc++.h>
using namespace std;
char s[5003];
int fora[5003];
int backa[5003];
int midb[5003];
int main() {
	scanf("%s",s+1);
	int suma = 0;
	int l = strlen(s+1);
	for(int i = 0;i <= l+1;i++) {
		if(s[i] == 'a')
			suma++;
		fora[i] = suma;
	}
	suma = 0;
	for(int i = l+1; i>= 0;i--) {
		if(s[i] == 'a')
			suma++;
		backa[i] = suma;
	}
	int sumb = 0;
	for(int i = 0;i <= l+1;i++) {
		if(s[i] == 'b')
			sumb++;
		midb[i] = sumb;
	}
	int ans = 0;
	for(int i = 0;i <= l+1;i++) 
		for(int j = i+1;j <= l+1;j++) {
			ans = max(ans,fora[i] + midb[j-1] - midb[i] + backa[j]);
		}
	cout<<ans;	
}
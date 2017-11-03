#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int t,m,n;
char s[1000001];
lli r[1000010];
lli k[1000010];
int main() {
	cin>>t;
	while(t--) {
		cin>>m>>n;
		scanf("%s",s);
		lli rans = 0,kans = 0;
		lli countR = 0,countK = 0;
		int len = strlen(s);
		memset(r,0,sizeof(r));
		memset(k,0,sizeof(k));
		for(int i = 0;s[i] != '\0';i++) {
			if(s[i] == 'R') {
				countR++;
				r[countR] = i+1;
			}
			else {
				countK++;
				k[countK] = i+1;
			}
		}

		for(int i = 1;i <= countR;i++) {
			//cout<<r[m+i-1]<<endl;
			if(r[m+i-1] != 0) {
				if(r[m+i] == 0)
					rans += (r[i]- (r[i-1] == 0 ? 0 : r[i-1]))*(len - r[m+i-1] + 1);
				else
					rans += (r[i]- (r[i-1] == 0 ? 0 : r[i-1]))*(r[m+i] - r[m+i-1]);
			}
			else
				break;
		}
		for(int i = 1;i <= countK;i++) {
			if(k[n+i-1] != 0) {
				if(k[n+i] == 0)
					kans += (k[i]-(k[i-1] == 0 ? 0 : k[i-1]))*(len-k[n+i-1]+1);
				else
					kans += (k[i]-(k[i-1] == 0 ? 0 : k[i-1]))*(k[n+i] - k[n+i-1]);	
			}
			else
				break;
		}
		if(m == 0) {
			lli cont = 0;
			if(k[1] != 0)
				cont = 1;
			int flag = 0;
			for(int i  = 2;i <= countK;i++) {
				if(k[i] == k[i-1] + 1) {
					cont++;
					flag = 0;
				}
				else {
					flag = 1;
					rans += (cont*(cont+1))/2; ;
					cont = 1;
				}
			}
			if(!flag)
				rans += (cont*(cont+1))/2;;
		}
		if(n == 0) {
			lli cont = 0;
			if(r[1] != 0)
				cont = 1;
			int flag = 0;
			for(int i  = 2;i <= countR;i++) {
				if(r[i] == r[i-1] + 1) {
					cont++;
					flag = 0;
				}
				else {
					flag = 1;
					kans += (cont*(cont+1))/2;;
					cont = 1;
				}
			}
			if(!flag)
				kans += (cont*(cont+1))/2;
		}
		cout<<rans<<" "<<kans<<endl;
	}
}
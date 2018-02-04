#include <bits/stdc++.h>
using namespace std;
int m,a[101];
int main() {
	cin>>m;
	for(int i = 1;i <= m;i++)
		scanf("%d",&a[i]);
	for(int k = 2;i <= 1000000;i++) {
		int x = a[1]%k;
		bool flag = true;
		for(int i = 2;i <= m;i++) {
			if(a[i]%k != x) {
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<k<<" ";
	}
	return  0;
}
#include <bits/stdc++.h>
using namespace std;
long int a[100001];
int n;
int main() {
	cin>>n;
	for(int i = 0;i < n;i++)
		scanf("%ld",&a[i]);
	int ans = 1,temp = 1;
	for(int i = 0;i < n-1;i++) {
		if(a[i] < a[i+1]) {
			temp++;
		}
		else  {
			temp = 1;
		}
		ans = max(temp,ans);
	}
	printf("%d", ans);
}
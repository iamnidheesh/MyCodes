#include <bits/stdc++.h>
using namespace std;
int n,t;
int a[3*10001];
int main() {
	cin>>n>>t;
	for(int i = 1;i <= n-1;i++) 
		scanf("%d",&a[i]);
	int curr = 1,next = curr + a[curr],flag = 0;
	while(curr < t) {
		curr = next;
		if(curr == t) {
			flag = 1;
			break;
		}
		next = curr + a[curr];
	}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n"); 
}
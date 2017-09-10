#include <bits/stdc++.h>
using namespace std;
int n;
pair <long int,long int> a[100001];
int main() {
	cin>>n;
	int ans = 0;
	long int occ = 0;
	for(int i = 0;i < n;i++)
		scanf("%ld%ld",&a[i].first,&a[i].second);
	ans++;//left
	occ = a[0].first;
	for(int i = 1;i < n-1;i++) {
		if(a[i].first - a[i].second > occ) {
			ans++;
			occ = a[i].first;//left
		}
		else if (a[i].first + a[i].second  < a[i+1].first) {
			ans++;
			occ = a[i].first + a[i].second;//right
		}
		else
			occ = a[i].first;
	}
	if(n > 1)
		ans++;//right
	printf("%d",ans);
}
#include <iostream>
#include <cstdio>
using namespace std;
int n;
long int a[1000001];
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++)
		scanf("%ld",&a[i]);
	int deathCount = 0;
	int deathIndex = n+1;
	for(int i = n;i > 1;i--) {
		if(i - a[i] < deathIndex && a[i] != 0) {
			if(deathIndex < i)
				deathCount += deathIndex - max((i - a[i]),(long int)1);
			else
				deathCount += min(a[i],(long int)i-1);
			deathIndex = max(i - a[i],(long int)0);
		}
		if(deathIndex == 0)
			break;
	}
	cout<<n - deathCount;
}
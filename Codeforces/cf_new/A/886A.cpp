#include <iostream>
using namespace std;
int a[7];
int main() {
	int s1 = 0;
	for(int i = 1;i <= 6;i++) {
		cin>>a[i];
		s1 += a[i];
	}
	for(int i = 1;i <= 6;i++)
		for(int j = 1;j < i;j++ )
			for(int k = 1;k < j;k++) {
				if(a[i]+a[j]+a[k] == s1 - a[i]-a[j]-a[k]) {
					cout<<"YES";
					return 0;
				}
			}
	cout<<"NO";
	return 0;
}
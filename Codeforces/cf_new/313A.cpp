#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main() {
	cin>>n;
	if(n > 0)
		printf("%d",n);
	else {
		int x = n/10;
		int y = n/10 - (-n)%10 + (-n/10)%10;
		cout<<max(x,y);
	}
}
#include <iostream>
using namespace std;
int main() {
	int a[101],n,b[101];
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		b[a[i]] = i;
	}
	for(int i = 1;i <= n;i++)
		cout<<b[i]<<" ";
}
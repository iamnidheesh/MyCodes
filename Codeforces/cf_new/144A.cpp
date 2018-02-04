#include <iostream>
using namespace std;
int main() {
	int n,a[101];
	cin>>n;
	int ans = 0,front = 0,end = 0,ma = 1,mi = 100;
	for(int i = 0;i < n;i++) {
		cin>>a[i];
		if(ma < a[i])
			ma  = a[i] , front = i;
		if(mi >= a[i])
			mi = a[i] ,end = i;
	}
	if(front < end)
		ans = front + n-1 - end;
	else
		ans = front + n-1 - end - 1;
	cout<<ans;

}
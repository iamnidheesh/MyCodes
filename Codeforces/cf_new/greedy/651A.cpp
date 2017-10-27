#include <bits/stdc++.h>
using namespace std;
int a,b;
int main() {
	cin>>a>>b;
	int ch;
	int ans = 0;
	if(a > b)
		ch = 2;
	else
		ch = 1;
	while( (a >= 2 and b >= 1 )|| (b >= 2 and a >= 1 )) {
		ans++;
		if(ch == 1) {
			a += 1;
			b -= 2;
		}
		if(ch == 2) {
			b += 1;
			a -= 2;
		}
		if(a > b)
			ch = 2;
		else
			ch = 1;
	}
	cout<<ans;
}
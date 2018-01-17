#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b;
	cin>>a>>b;
	if(abs(a-b) <= 1)
		if(a == 0 && a == b)
		cout<<"NO";
		else
			cout<<"YES";
	else
		cout<<"NO";
}
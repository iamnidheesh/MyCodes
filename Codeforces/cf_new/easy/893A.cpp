#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n,a[101];
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	bool flag = true;
	int p1 = 1,p2 = 2,spec = 3;
	for(int i = 1;i <= n;i++) {
		if(a[i] != p1 && a[i] != p2) {
			flag = false;
			break;
		}
		else {
			if(a[i] == p1) {
				int temp = p2;
				p2 = spec;
				spec = temp;
			}
			if(a[i] == p2) {
				int temp = p1;
				p1 = spec;
				spec = temp;
			}
		}
	}
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
}
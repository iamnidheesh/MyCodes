#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int t,n;
int main() {
	cin>>t;
	while(t--) {
		v.clear();
		v.push_back(0);
		v.push_back(2);
		v.push_back(1);
		cin>>n;
		for(int i = 3;i <= n;i++) {
			if(i%2 == 0) {
				v.push_back(v[i-2]);
				v[i-2] = v[i-1];
				v[i-1] = i;
			}
			else {
				v.push_back(v[i-1]);
				v[i-1] = i;
			}
		}
		for(int i = 1;i <= n;i++) {
			printf("%d ",v[i]);
		}
		printf("\n");
	}
}
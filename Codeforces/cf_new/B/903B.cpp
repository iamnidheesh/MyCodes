#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int h1,a1,c1,h2,a2;
int main() {
	cin>>h1>>a1>>c1>>h2>>a2;
	int maxHealth = h1;
	vector <bool> v;
	while(1) {
		if(h2 - a1 <= 0) {
			v.push_back(true);
			break;
		}
		else {
			if(h1 - a2 <= 0) {
				v.push_back(false);
				h1 = h1+c1-a2;
			}
			else {
				v.push_back(true);
				h2 = h2 - a1;
				h1 = h1 - a2;
			}
		}
		
	}
	cout<<v.size()<<endl;
	for(int i = 0;i < v.size();i++) {
		if(v[i])
			printf("STRIKE\n");
		else
			printf("HEAL\n");
	}

}
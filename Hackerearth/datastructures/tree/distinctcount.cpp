#include <bits/stdc++.h>
using namespace std;
int t,n,x;
long int z;
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>x;
		set <long int> s;
		for(int i = 1;i <= n;i++)
			cin>>z,s.insert(z);
		if(s.size() == x)
			printf("Good\n");
		else if (s.size() > x)
			printf("Average\n");
		else
			printf("Bad\n");
	}
}
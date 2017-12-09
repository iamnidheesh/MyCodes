#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector <long int> v;
int main() {
	int n;
	cin>>n;
	int k = 1;
	while(1) {
		long int num = ((1 << k) - 1)*(1 << (k-1));
		k++;
		if(num > n || num < 0)
			break;
		v.push_back(num);
	}
	for(int i = v.size()-1;i >= 0;i--) {
		if(n%v[i] == 0) {
			cout<<v[i];
			break;
		}
	}
}
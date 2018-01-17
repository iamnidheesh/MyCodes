#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin>>n;
	vector <int> v;
	for(int i = 2;i <= n;i+= 2)
		v.push_back(i);
	for(int i = 1;i <= n;i+= 2)
		v.push_back(i);
	for(int i = 2;i <= n;i+= 2)
		v.push_back(i);
	cout<<v.size()<<endl;
	for(int i = 0;i < v.size();i++)
		cout<<v[i]<<" ";
	
	
}
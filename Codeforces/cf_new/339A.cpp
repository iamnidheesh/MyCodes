#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin>>s;
	vector<char> v;
	for(int i = 0;i < s.size();i+=2)
		v.push_back(s[i]);
	sort(v.begin(),v.end());
	for(int i = 0;i < v.size()-1;i++) {
		cout<<v[i]<<'+';
	}
	cout<<v[v.size()-1];
}
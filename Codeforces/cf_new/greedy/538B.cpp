#include <bits/stdc++.h>
using namespace std;
string s;
vector <string> v;
int main() {
	cin>>s;
	int index = 0;
	while(index < s.size()) {
		for(int i = 0;i < s[index] - '0';i++) {
			string temp = "1";
			for(int j = index+1;j < s.size();j++) {
				if(s[j] - '0' > 0) {
					temp += '1';
					s[j] -= 1;
				}
				else
					temp += '0';
			}
			v.push_back(temp);
		}
		index++;
	}
	cout<<v.size()<<endl;
	for(int i = 0;i < v.size();i++)
		cout<<v[i]<<" ";

}
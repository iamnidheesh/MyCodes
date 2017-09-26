#include <bits/stdc++.h>
using namespace  std;
int t;
string s;
map <string,int> m;
pair <int,string> p[3001];
int main() {
	cin>>t;
	cin.ignore();
	int ct,pos;
	while(t--) {
		getline(cin,s);
		for(int i = 0;i < s.size();i++) {
			if(s[i] == '#') {
				ct = 1;
				pos = i;
				while(s[i] != ' ' && i < s.size()) {
					ct++;
					i++;
				}
				m[s.substr(pos,ct)]++;
			}
		}
	}
	int j = 0;
	for(map <string,int> :: iterator it = m.begin();it != m.end();it++) {
		p[j].first = it->second;
		p[j].second = it->first;
		j++;
	}
	sort(p,p+j);
	for(int i = j-5;i < j;i++) {
		cout<<p[i].second<<" : " << p[i].first<<endl;
	}
}
#include <bits/stdc++.h>
using namespace  std;
int n;
string s[101];
map < pair < pair <char,char> , int >, int > m;
int main()
{
	cin>>n;
	for(int i = 0;i < n;i++) {
		cin>>s[i];
		int sum = 0;
    	for(int j = 0;j < s[i].size();j++) {
    		sum = sum + pow((s[i][j] - 'a'+20),2);
    	}
    	m[make_pair(make_pair(s[i][0],s[i][s[i].size()-1]),sum)] = 1;
	}
	printf("%lu",m.size());
    return 0;
}

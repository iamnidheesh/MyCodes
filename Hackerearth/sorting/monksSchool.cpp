#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
map <string, vector < pair < int,string> > > teacher;
map <string, vector < pair < int,string> > > :: iterator it;
int n,m,age;
string t,s;
int main()
{
	cin>>n>>m;
	for(int i = 0;i < n;i++)
		cin>>s;
	for(int i = 0;i < m;i++) {
		cin>>t>>s>>age;
		teacher[t].push_back({age,s});
	}
	for(it = teacher.begin();it != teacher.end();it++) {
		sort((it->second).begin(),(it->second).end());
		cout<<it->first<<endl;
		for(int i = 0;i < (it->second).size();i++) {
			cout<<(it->second)[i].second<<" "<<(it->second)[i].first<<endl;
		}
	}
    return 0;
}

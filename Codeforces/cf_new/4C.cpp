#include <bits/stdc++.h>
using namespace std;
int n;
string k;
map <string ,int > m;
int main() {
	cin>>n;
	while(n--) {
		cin>>k;
		if(!m[k])
			cout<<"OK"<<endl;
		else 
			cout<<k + to_string(m[k])<<endl;
		m[k]++;		
	}
}
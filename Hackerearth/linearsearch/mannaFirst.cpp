#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
	cin>>t;
	while(t--) {
		cin>>s;
		int pos = 0,temp1,temp;
		int suvo = 0,suvojit = 0;
		while(pos < s.size()) {
			temp = -1;temp1 = -1;
			temp = s.substr(pos,s.size()).find("SUVO");
			temp1 = s.substr(pos,s.size()).find("SUVOJIT");
			if(temp1 != string::npos && temp != string::npos && temp1 == temp) {
				pos += temp+7;
				suvojit++;
			
			}
			else if(temp != string::npos) {
				pos += temp+4;
				suvo++;
			
			}
			else if(temp1 != string::npos){
				pos += temp1+7;
			    suvojit++;
			}
			else 
				break;
			
		}
		cout<<"SUVO = "<<suvo<<", SUVOJIT = "<<suvojit<<endl;
	}
}
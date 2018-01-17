#include <bits/stdc++.h>
using namespace std;
string s;
int Count(string str) {
	int found = 0;
	int count = 0;
	int len = s.size();
	while(1) {
		if((found = s.find(str,found)) != -1) {
			count++;
			found += str.size();
		}
		else
			break;
	}
	return count;
}
int main() {
	cin>>s;
	int count = 0;
	count = Count("Nikita") + Count("Ann") + Count("Olya")
			+ Count("Slava") + Count("Danil");
	if(count == 1)
		cout<<"YES";
	else
		cout<<"NO";
}
#include <iostream>
#include <algorithm>
using namespace std;
int s,n;
pair <int,int> xy[1001];
int main() {
	cin>>s>>n;
	for(int i = 0;i < n;i++)
		cin>>xy[i].first>>xy[i].second;
	sort(xy,xy+n);
	bool flag = true;
	for(int i = 0;i < n;i++) {
		if(s > xy[i].first)
			s += xy[i].second;
		else {
			flag = false;
			break;
		}
	}
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
}
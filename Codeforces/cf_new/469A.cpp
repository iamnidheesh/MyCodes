#include <set>
#include <iostream>
using namespace std;
int main() {
	int n,x,y,a,b;
	set <int> s;
	cin>>n;
	cin>>x;
	for(int i = 1;i <= x;i++) {
		cin>>a;
		s.insert(a);
	}
	cin>>y;
	for(int i = 1;i <= y;i++) {
		cin>>b;
		s.insert(b);
	}
	if(s.size() == n)
		cout<<"I become the guy.";
	else
		cout<<"Oh, my keyboard!";
}
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int h;
int a[2*100001];
vector <int> v1,v2;
int main() {
	cin>>h;
	int ct = 0;
	cin>>a[0];
	bool flag = true;
	for(int i = 1;i <= h;i++) {
		cin>>a[i];
		if(a[i] >= 2 && a[i-1] >= 2)
			flag = false;
		
	}
	if(flag) {
		cout<<"perfect";
		return 0;
	}
	cout<<"ambiguous"<<endl;
	v1.push_back(0);
	v2.push_back(0);
	for(int j = 1;j <= a[1];j++) {
		v1.push_back(1);v2.push_back(1);
	}
	for(int i = 2;i <= h;i++) {
		if(a[i-1] > 1) {
			int x1 = v1.size();
			for(int j = 1;j <= a[i];j++) {
				v1.push_back(x1);
				if(j == 1)
					v2.push_back(x1-1);
				else
					v2.push_back(x1);
			}
		}
		else {
			int x1 = v1.size();
			for(int j = 1;j <= a[i];j++) {
				v1.push_back(x1);
				v2.push_back(x1);
			}
		}
	}
	for(int i = 0;i < v1.size();i++)
		printf("%d ",v1[i]);
	cout<<endl;
	for(int i = 0;i < v2.size();i++)
		printf("%d ",v2[i]);

}
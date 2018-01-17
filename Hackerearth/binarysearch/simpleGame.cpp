#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int n,m,x;
vector <li > a,b;
int main()
{
	cin>>n>>m;
	for(int i = 0;i < n;i++)
		cin>>x,a.push_back(x);
	for(int i = 0;i < m;i++)
		cin>>x,b.push_back(x);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	lli scoreA = 0,scoreB = 0;
	for(int i = 0;i < n;i++) {
		lli x1,x2;
		x1 = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
		x2 = b.end() - upper_bound(b.begin(),b.end(),a[i]);
		scoreA += x1*x2;
	}
	for(int i = 0;i < m;i++) {
		lli x1,x2;
		x1 = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
		x2 = a.end() - upper_bound(a.begin(),a.end(),b[i]);
		scoreB += x1*x2;
	}
	if(scoreB > scoreA)
		cout<<"!Monk "<<scoreB-scoreA;
	else if(scoreA > scoreB)
		cout<<"Monk "<<scoreA - scoreB;
	else
		cout<<"Tie";
    return 0;
}
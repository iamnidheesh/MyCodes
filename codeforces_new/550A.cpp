#include <bits/stdc++.h>
using namespace std;
string s;
int b,c,d,n,m,i,k;
int main() {
	cin>>s;
    b=s.find("AB");
    c=s.find("BA",b+2);
    d=s.find("BA");
    n=s.find("AB",d+2);
    if ((b>=0 && c>=0) || (d>=0 && n>=0)) cout<<"YES";
    else cout<<"NO";
}
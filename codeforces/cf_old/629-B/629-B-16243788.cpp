#include<stdio.h>
#include<iostream>
using namespace std;
int dm[367];
int df[367];
int mp[367];
int main() {
	int n;
	char c;
	int a,b;
	scanf("%d",&n);
	int k;
	while(n--) {
		cin>>c>>a>>b;

		if(c=='F') {
			for(k=a;k<=b;k++)
				df[k]++;	
		}

		else {
			for(k=a;k<=b;k++)
				dm[k]++;
		
		}
	}
	int m=0;
	for(k=1;k<=366;k++)
		{mp[k]=dm[k]>df[k]?df[k]:dm[k];}
	for(k=1;k<=366;k++)
		if(mp[k]>m)
			m=mp[k];
	cout<<2*m;
	return 0;
	}
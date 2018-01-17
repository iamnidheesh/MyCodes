#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int t,n,vd,cd,pd,fd,v[21],c[21],f[21],p[21];
bool isSubset(int x,int vsum,int csum,int fsum,int psum) {
	if(x == n)
	    if(!vsum&&!csum&&!fsum&&!psum)
		    return true;
		else
		    return false;
	if(!vsum&&!csum&&!fsum&&!psum)
		return true;
	return isSubset(x+1,vsum-v[x],csum-c[x],fsum-f[x],psum-p[x])
	||isSubset(x+1,vsum,csum,fsum,psum);
}
int main()
{	
	cin>>vd>>cd>>fd>>pd;
	cin>>n;
	for(int i = 0;i < n;i++) {
		cin>>v[i]>>c[i]>>f[i]>>p[i];
	}
	if(isSubset(0,vd,cd,fd,pd))
		cout<<"YES";
	else
		cout<<"NO";
    return 0;
}

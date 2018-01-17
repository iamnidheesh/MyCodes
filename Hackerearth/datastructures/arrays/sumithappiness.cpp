#include <bits/stdc++.h>
using namespace std;
int t,n;
long long int a;
int main() {
	long long int ans = 0;
	cin>>t;
	while(t--) {
		ans = 0;
		long long int pc = 0,nc = 0,tnsum = 0,nsum = 0,psum = 0;
		cin>>n;
		vector <long long int> v;
		for(int i = 0;i < n;i++) {
			cin>>a;
			if(a < 0) {
				tnsum += a;
				v.push_back(a);
			}
			else {
				pc++;
				psum += a;
			}
		}
		sort(v.begin(),v.end());
		for(int i = v.size()-1;i >= 0;i--) {
			if((pc+nc)*(psum+nsum) < (pc+nc+1)*(psum+nsum+v[i])) {
				nc += 1;
				nsum += v[i];
			}
		}
		ans = (pc+nc)*(psum+nsum) + (tnsum - nsum);
		cout<<ans<<endl;
	}
}
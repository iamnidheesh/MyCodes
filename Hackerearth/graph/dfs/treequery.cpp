#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int N,M,X,Y;
vector <int> g1[100001],g2[100001];
int main()
{
	int c1 = 0,c2 = 0;
	cin>>N>>M;
	while(M--) {
		scanf("%d%d",&X,&Y);
		g1[X].push_back(Y);
		g2[Y].push_back(X);
	}
	for(int i = 1;i <= N;i++) {
		if(g1[i].size() == 0)
			c1++;
		if(g2[i].size() == 0)
			c2++;
	}
	printf("%d",max(c1,c2));
    return 0;
}

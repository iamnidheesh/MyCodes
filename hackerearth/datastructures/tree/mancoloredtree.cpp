#include <bits/stdc++.h>
using namespace std;
int n,c;
int x,parent[100001],color[100001];
int main() {
	cin>>n>>c;
	parent[1] = -1;
	for(int i = 1;i <= n-1;i++) {
		scanf("%d",&x);
		parent[i+1] = x;
	}
	for(int i = 1;i <= n;i++)
		scanf("%d",&color[i]);
	for(int i = 1;i <= n;i++) {
		int temp = i;
		int col = color[i];
		int flag = -1;
		while(parent[temp] != -1) {
			if(col == color[parent[temp]]) {
				flag = parent[temp];
				break;
			}
			temp = parent[temp];
		}
		printf("%d ",flag);
	}
}
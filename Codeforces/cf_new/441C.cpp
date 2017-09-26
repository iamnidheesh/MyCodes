#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int main() {
	cin>>n>>m>>k;
	int seg = (n*m)/k;
	int move = 1; //1 -- right, 2-- left
	int x = 1,y = 1;
	for(int i = 1;i < k;i++) {
		printf("%d ",seg);
		for(int j = 0;j < seg;j++) {
			printf("%d %d ",x,y);
			if(move == 1 && y == m)
				move = 2,x++;
			else if(move == 2 && y == 1)
				move = 1,x++;
			else if(move == 1)
				y++;
			else
				y--;
		}
		printf("\n");
	}
	printf("%d ",n*m - (k-1)*seg);
	for(int i = 0;i < n*m - (k-1)*seg;i++) {
		printf("%d %d ",x,y);
			if(move == 1 && y == m)
				move = 2,x++;
			else if(move == 2 && y == 1)
				move = 1,x++;
			else if(move == 1)
				y++;
			else
				y--;
	}
}
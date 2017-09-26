#include <bits/stdc++.h>
using namespace std;
int t;
// maximum contiguos subarray problem.
// important
char s[1000001];
int mem[1000001];
int main() {
	cin>>t;
	while(t--) {
		scanf("%s",s);
		int len = strlen(s),c = 0;
		for(int i = 0;i < len;i++) {
			if(s[i] == 'R') {
				c++;
				mem[i] = -1;
			}
			else
				mem[i] = 1;
		}
		int cur_max = mem[0];
		int max_so_far = mem[0];
		for(int i = 1;i < len;i++) {
			cur_max = max(mem[i],cur_max+mem[i]);
			max_so_far = max(max_so_far,cur_max);
		}
		printf("%d\n",c + max_so_far);
	}
}
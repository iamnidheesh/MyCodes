#include <bits/stdc++.h>
using namespace std;
int n,m,y,x;
vector <int> adj[10001];
int state[10001],tent[10001];
vector <int> component[10001];
int ans[10001];
void dfs(int x,int con) {

	state[x] = con;
	component[con].push_back(x);
//	printf("hello\n");
	for(vector <int> :: iterator it = adj[x].begin(); it != adj[x].end();it++) {
		int i = *it;
		if(!state[i]) {
			dfs(i,con);
		}
	}
}
int main() {

	cin>>n;
		cin>>m;
		for(int i = 1;i <= n;i++)
			scanf("%d",&tent[i]);
		for(int i = 0;i < m;i++) {
			scanf("%d%d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int con = 0,temp,sum,id,kill = 0,injured = 0;
		for(int i = 1;i <= n;i++) {
			if(!state[i]) {
				con++;
				dfs(i,con);
			}
		}
		for(int i = 1;i <= con;i++) {
			temp = 0;sum = 0,id = 10001;
			for(int j = 0;j < component[i].size();j++) {
				sum += tent[component[i][j]];
				//printf("%d ",component[i][j]);
				if(tent[component[i][j]] > temp 
				|| tent[component[i][j]] == temp && component[i][j] < id  ) 
					temp = tent[component[i][j]],id = component[i][j];
			}
			//printf("\n");
			ans[i-1] = id,kill += temp,injured += sum - temp;
			
		}
		sort(ans,ans+con);
		printf("%d %d\n",kill,injured );
		for(int i = 0;i < con;i++)
			printf("%d ",ans[i]);
		
}
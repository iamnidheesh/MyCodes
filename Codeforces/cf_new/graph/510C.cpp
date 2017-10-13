#include <bits/stdc++.h>
using namespace std;
/* to check cycle in a directed graph check if 
vertex you are trying to visit again is not in the recursoin stack*/
int n;
string s,p;
bool flag = true;
vector <int> adj[200];
vector <char> toporder;
int vis[200];
void topsort(int x) {
	if(flag == false)
		return;
	vis[x] = 1;
	for(int i = 0;i < adj[x].size();i++) {
		int v = adj[x][i];
		if(!vis[v])
			topsort(v);
		else if(vis[v] == 1){
			flag = false;
			return;
		}
	}
	vis[x] = 2;
	toporder.push_back(x);

}
int main() {
	cin>>n>>p;
	for(int i = 1;i < n;i++) {
		cin>>s;
		if(s.size() < p.size() && p.find(s) == 0) {
			cout<<"Impossible";
			return 0;
		}
		int k = 0;
		while(k < s.size() && k < p.size() && s[k] == p[k]) {
			k++;
		}
		if(k < s.size() && k < p.size()) {
			adj[p[k]].push_back(s[k]);
		}
		p = s;
	}
	for(char i = 'a';i <= 'z';i++) {
		if(!vis[i]) {
			topsort(i);
			if(!flag) {
				cout<<"Impossible";
				return 0;
			}
		}
	}
	for(int i = toporder.size()-1;i >= 0;i--) {
		cout<<toporder[i];
	}

}
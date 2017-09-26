//used stackoverflow
// do DFS and while backtracking,
//if child vertex is not included,
//include its parent(if not already included)
#include<bits/stdc++.h>
using namespace std;
int n,cnt;
bool vis[100001];
bool incl[100001];
vector <int> v[100001];
void dfs(int s) {
    vis[s] = true;
    for(int i = 0;i < v[s].size();i++) {
        if(!vis[v[s][i]]) {
            dfs(v[s][i]);
            if(!incl[v[s][i]] && !incl[s]) {
                incl[s] = true;
                cnt++;
            }
        }
    }
}
int main() {
    cin>>n;
    int a,b;
    for(int i = 1;i <= n-1;i++) {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
        vis[i] = false;
        incl[i] = false;
    }
    vis[n] = false;
    incl[n] = false;
    dfs(1);
    printf("%d\n",cnt);
    return 0;
}

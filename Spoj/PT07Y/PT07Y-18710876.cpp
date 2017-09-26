#include<bits/stdc++.h>
using namespace std;
int vis[10004];
queue <int> q;
vector <int> v[10004];
int x,y,k,n;
void bfs(int s) {
    q.push(s);
    vis[s] = 1;
    int curr;
    int flag = 1;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        for( vector <int> :: iterator it = v[curr].begin();it != v[curr].end();it++) {
            if(!vis[*it]) {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
}
int main() {

        int f1 = 1,f2 = 1;
        scanf("%d%d",&n,&k);
        for(int i = 0;i < k;i++) {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        bfs(1);
        if(k != n-1)
            f1 = 0;
        for(int i = 1;i <= n;i++)
            if(vis[i] != 1) {
                f2 = 0;
                break;
            }
        if(f1&&f2)
            printf("YES");
        else
            printf("NO");
}



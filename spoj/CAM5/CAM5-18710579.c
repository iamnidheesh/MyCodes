#include<bits/stdc++.h>
using namespace std;
int vis[100001];
queue <int> q;
vector <int> v[100001];
int t,x,y,k,n,c;
void bfs(int s) {
    q.push(s);
    vis[s] = 1;
    int curr;
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

    cin>>t;
    while(t--) {
        c = 0;
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&k);
        for(int i = 0;i < k;i++) {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                if(!v[i].empty())
                    bfs(i);
                c++;
            }
        }

        for(int i = 0;i < n;i++)
            v[i].clear();
        printf("%d\n",c);
    }


}


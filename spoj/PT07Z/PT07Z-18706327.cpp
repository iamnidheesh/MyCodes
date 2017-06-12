#include<bits/stdc++.h>
using namespace std;
queue <int> q;
vector <int> a[10001];
int n,u,v;
int dis[10001];
int bfs(int s) {
    int curr;
    q.push(s);
    memset(dis,-1,sizeof(dis));
    dis[s] = 0;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        for(vector <int> :: iterator it = a[curr].begin();it != a[curr].end();it++) {
            if(dis[*it] == -1) {
                q.push(*it);
                dis[*it] = dis[curr] + 1;
            }
        }
    }
    return curr;
}
int main() {
    cin>>n;
    for(int i = 0;i < n-1;i++) {
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
   int ns = bfs(u);
   int ans = bfs(ns);
   printf("%d\n",dis[ans]);
}

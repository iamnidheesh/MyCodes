#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
vector <int> v[100005];
queue <int> q;
int dis[100005];
int bfs(int s) {
    memset(dis,-1,(n+1)*sizeof(int));
    q.push(s);
    dis[s] = 0;
    int curr;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        for(vector <int> :: iterator it = v[curr].begin();it != v[curr].end();it++) {
            if(dis[*it] == -1) {
                dis[*it] = 1 + dis[curr];
                q.push(*it);
            }
        }
    }
    return curr;
}
int main() {
    cin>>t;
    while(t--) {
        scanf("%d",&n);
        for(int i = 0;i < n;i++) {
            v[i].clear();
        }
        for(int i = 0;i < n-1;i++) {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int l = dis[bfs(bfs(0))];
        if(l%2 == 0)
            printf("%d\n",l/2);
        else
            printf("%d\n",(l+1)/2);
    }
}

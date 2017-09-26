#include<bits/stdc++.h>
using namespace std;
vector <int> s[2003];
int c[2003];
int main() {
    int t,n,m,u,v;
    cin>>t;
    for(int j = 1;j <= t;j++) {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++) {
            s[i].clear();
            c[i] = 0;
        }
        for(int i = 0;i < m;i++) {
            scanf("%d%d",&u,&v);
            s[u].push_back(v);
            s[v].push_back(u);
        }
        int flag = 1;
        queue <int> q;
        for(int i = 1;i <= n;i++) {
            if(c[i] == 0) {
                c[i] = 1;// red
                q.push(i);
            }
            else
                continue;
            while(!q.empty()) {
                int val = q.front();
                q.pop();
                int next;
                if(c[val] == 1)
                    next = 2;
                else
                    next = 1;
                for(vector <int> :: iterator it = s[val].begin(); it != s[val].end();it++) {
                    if(c[*it] == c[val]) {
                        flag = 0;
                        break;
                    }
                    if(c[*it] == 0) {
                        q.push(*it);
                        c[*it] = next;
                    }
                }
                if(flag == 0)
                    break;
            }
            if(flag == 0)
                break;
        }
        printf("Scenario #%d:\n",j);
        if(flag)
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
    }

    return 0;
}

#include<bits/stdc++.h> // kosaraju's algorithm stongly connected components
using namespace std;
char a[105][105];
int mark[105][105];
int vis[105];
int t,n;
stack <int> s;
void dfs(int i) {

    vis[i] = 1;
    for(int j = 0;j < n;j++) {
        if((a[i][j] == 'Y' )&& !vis[j])
          dfs(j);
    }
    s.push(i);
}
void dfx(int i) {
   // printf("%d --> ",i);
    vis[i] = 1;
    for(int j = 0;j < n;j++) {
        if((a[i][j] == 'Y') && !vis[j])
          dfx(j);
    }
}
int main() {

    cin>>t;
    while(t--) {
        scanf("%d",&n);
        for(int i = 0;i < n;i++) {
            scanf("%s",a[i]);
            vis[i] = 0;
        }
        s = stack <int> ();
        for(int i = 0;i < n;i++) {
            if(vis[i] == 0)
                dfs(i);
        }
        memset(mark,0,sizeof(mark));
        for(int i = 0;i < n;i++)
            for(int j  = 0;j < n;j++)
               if(!mark[i][j] && !mark[j][i]) {
                    if(a[i][j] == 'Y' && a[j][i] == 'N') {
                        a[i][j] = 'N';
                        a[j][i] = 'Y';
                    }
                    else if(a[i][j] == 'N' && a[j][i] == 'Y') {
                        a[i][j] = 'Y';
                        a[j][i] = 'N';
                    }
                    mark[i][j] = 1;
                    mark[j][i] = 1;
               }
        int c = 0;
       // printf("%d\n",s.size());
        memset(vis,0,sizeof(vis));
        while(!s.empty()) {
            int i = s.top();
            s.pop();
            if(vis[i] == 0) {
                dfx(i);
              //  printf("\n");
                c++;
            }
        }
        printf("%d\n",c);
    }
}

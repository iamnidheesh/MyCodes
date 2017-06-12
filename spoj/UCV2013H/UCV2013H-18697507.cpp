#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[255][255];
int vis[255][255];
int slick;
map < int ,int > d;
void dfs(int i,int j) {
    vis[i][j] = 1;
    if(a[i][j] == 1)
        slick++;
    if(i != n-1) {
        if(!vis[i+1][j] && a[i+1][j] == 1)
            dfs(i+1,j);
    }
    if(j != n-1) {
        if(!vis[i][j+1] && a[i][j+1] == 1)
            dfs(i,j+1);
    }
    if(i != 0) {
        if(!vis[i-1][j] && a[i-1][j] == 1)
            dfs(i-1,j);
    }
    if(j != 0) {
        if(!vis[i][j-1] && a[i][j-1] == 1)
            dfs(i,j-1);
    }
}
int main() {
        while(1) {
            memset(vis,0,sizeof(vis));
            cin>>n>>m;
            if(n == 0)
                break;
            for(int i = 0;i < n;i++)
                for(int j = 0;j < m;j++) {
                    scanf("%d",&a[i][j]);
            }
            int co = 0;
            for(int i = 0;i < n;i++)
                for(int j = 0;j < m;j++) {
                    if(a[i][j] == 1 && !vis[i][j]) {
                        dfs(i,j);
                        d[slick]++;
                        co++;
                        slick = 0;
                    }
            }
            map <int,int> :: iterator it;
            printf("%d\n",co);
            for(it = d.begin();it != d.end();it++)
                printf("%d %d\n",it->first,it->second);
            d.clear();
        }
}

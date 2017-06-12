#include<bits/stdc++.h>
using namespace std;
int t,n,m,l;
char a[1005][1005];
int dis[1005][1005];
int dfs(int i,int j) {

    if(i != 0)
        if(dis[i-1][j] == -1 && a[i-1][j] == '.') {
            dis[i-1][j] = 1 + dis[i][j];
            dfs(i-1,j);
        }
    if(j != 0)
        if(dis[i][j-1] == -1 && a[i][j-1] == '.') {
            dis[i][j-1] = 1 + dis[i][j];
            dfs(i,j-1);
        }
    if(i != n-1)
        if(dis[i+1][j] == -1 && a[i+1][j] == '.') {
            dis[i+1][j] = 1 + dis[i][j];
            dfs(i+1,j);
        }
    if(j != m-1)
        if(dis[i][j+1] == -1 && a[i][j+1] == '.') {
            dis[i][j+1] = 1 + dis[i][j];
            dfs(i,j+1);
        }
}
int main() {
    cin>>t;
    while(t--) {
        memset(dis,-1,sizeof(dis));
        scanf("%d%d",&m,&n);
        for(int i = 0;i < n;i++) {
            scanf("%s",a[i]);
        }
        int flag = 1;
        for(int i = 0;i < n;i++) {
            for(int j = 0;a[i][j] != '\0';j++)
                if(a[i][j] == '.') {
                    dis[i][j] = 0;
                    dfs(i,j);
                    flag = 0;
                    break;
                }
                if(!flag)
                    break;
        }
        int k = 0,l = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(dis[i][j] > dis[k][l]) {
                    k = i;
                    l = j;

                }
            }
        }
        memset(dis,-1,sizeof(dis));
        dis[k][l] = 0;
        dfs(k,l);
        int ans = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if(dis[i][j] > ans) {
                    ans = dis[i][j];
                }
        printf("Maximum rope length is %d.\n",ans);
    }

}

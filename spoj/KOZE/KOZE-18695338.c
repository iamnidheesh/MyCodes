#include<bits/stdc++.h>
using namespace std;
char a[255][255];
int vis[255][255];
int n,m;
int buff,wolf,tb,tw;
int aw,ab;
int flag = 1;
void dfs(int i,int j) {

    vis[i][j]  = 1;
    if(i == n-1 || j == m-1) {
        flag = 0;
        return;
    }
    if(a[i][j] == 'k')
        buff++;
    else if(a[i][j] == 'v')
        wolf++;
    if(a[i+1][j] != '#' && vis[i+1][j] != 1)
        dfs(i+1,j);
    if(a[i][j+1] != '#' && vis[i][j+1] != 1)
        dfs(i,j+1);
    if(i != 0)
        if(a[i-1][j] != '#' && vis[i-1][j] != 1)
            dfs(i-1,j);
    if(j != 0)
        if(a[i][j-1] != '#' && vis[i][j-1] != 1)
            dfs(i,j-1);
}
int main() {

    cin>>n>>m;
    for(int i = 0;i < n;i++)
        scanf("%s",a[i]);
    for(int i = 0;i < n;i++)
        for(int j = 0;a[i][j] != '\0';j++) {
            buff = 0;
            wolf = 0;
            if(a[i][j] != '#' && vis[i][j] != 1)
                dfs(i,j);
            if(flag == 0) {
                flag = 1;
            }
            else {
                if(buff > wolf)
                    ab += buff;
                else
                    aw += wolf;
            }
        }
    printf("%d %d",ab,aw);

}

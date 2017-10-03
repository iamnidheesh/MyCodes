#include <bits/stdc++.h>
using namespace  std;
#define lli long long int
#define li long int
int N;
int vis[102][102];
int a[102][102];
int flag1 = false,flag2 =false;
void dfs(int i,int j,int ch) {
    vis[i][j] = ch;
    if(i == N && ch == 1)
        flag1 = true;
    if(j == N && ch == 2)
        flag2 = true;
    int row[8] = {1,-1,0,1,-1,0,1,-1};
    int col[8] = {1,1,1,-1,-1,-1,0,0};
    for(int q = 0;q < 8;q++) {
        int k = i + row[q];
        int l = j + col[q];
        if(k >= 1 && k <= N && l >= 1 && l <= N && !vis[k][l] && a[k][l] == ch)
            dfs(k,l,ch);
    }
}
int main()
{
    cin>>N;
    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= N;j++)
            cin>>a[i][j];
    for(int i = 1;i <= N;i++) {
        if(a[1][i] == 1 && !flag1 && !vis[1][i])
            dfs(1,i,1);
        if(a[i][1] == 2 && !flag2 && !vis[i][1])
            dfs(i,1,2);
    }
    if(flag1 && flag2)
        cout<<"AMBIGUOUS";
    else if(flag1 == true)
        cout<<1;
    else if(flag2 == true)
        cout<<2;
    else
        cout<<0;
    return 0;
}

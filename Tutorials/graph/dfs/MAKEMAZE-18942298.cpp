#include<bits/stdc++.h>
using namespace std;
int t,m,n;
char a[25][25];
int dis[25][25];
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
    if(i != m-1)
        if(dis[i+1][j] == -1 && a[i+1][j] == '.') {
            dis[i+1][j] = 1 + dis[i][j];
            dfs(i+1,j);
        }
    if(j != n-1)
        if(dis[i][j+1] == -1 && a[i][j+1] == '.') {
            dis[i][j+1] = 1 + dis[i][j];
            dfs(i,j+1);
        }
}
int main() {

    cin>>t;
    while(t--) {
        scanf("%d%d",&m,&n);
        for(int i = 0;i < m;i++)
            scanf("%s",a[i]);
        int c = 0,flag = 1;
        pair <int,int> s,d;
        for(int j = 0;j < n;j++) {
            if(a[0][j] == '.') {
                c++;
                if(c == 1 )
                    s = make_pair(0,j);
                else if( c == 2)
                    d = make_pair(0,j);
            }
            if(a[m-1][j] == '.' && m != 1) {
                 c++;
                if(c == 1 )
                    s = make_pair(m-1,j);
                else if( c == 2)
                    d = make_pair(m-1,j);
            }
        }
        for(int i = 1;i < m-1;i++) {
            if(a[i][0] == '.') {
                c++;
                if(c == 1 )
                    s = make_pair(i,0);
                else if( c == 2)
                    d = make_pair(i,0);
            }
            if(a[i][n-1] == '.' && n != 1) {
                 c++;
                if(c == 1 )
                    s = make_pair(i,n-1);
                else if( c == 2)
                    d = make_pair(i,n-1);
            }
        }
      //  printf("%d\n",c);
        if(c != 2)
            flag = 0;
        if(flag) {
            memset(dis,-1,sizeof(dis));
            dis[s.first][s.second] = 0;
            dfs(s.first,s.second);
           // printf("%d\n",dis[d.first][d.second]);
            if(dis[d.first][d.second] != -1)
                printf("valid\n");
            else
                printf("invalid\n");
        }
        else
            printf("invalid\n");
    }
}

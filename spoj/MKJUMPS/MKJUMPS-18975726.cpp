#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int a[15][15];
int cnt1,cnt2,val;
int visit[15][15];
int maxval(int * b) {
    int val = -1;
    for(int i = 0;i < 8;i++)
        val = max(val,b[i]);
    return val;
}
int dfs(int i,int j) {

    visit[i][j] = 1;
    int b[8];
    memset(b,0,sizeof(b));
    if(a[i-2][j-1] != 0 && !visit[i-2][j-1]) {
       b[0] = 1 + dfs(i-2,j-1);
    }
    if(a[i-2][j+1] != 0 && !visit[i-2][j+1] ) {
       b[1] = 1 + dfs(i-2,j+1);
    }
    if(a[i-1][j-2] != 0 && !visit[i-1][j-2]) {
        b[2] = 1 + dfs(i-1,j-2);
    }
    if(a[i-1][j+2] != 0 && !visit[i-1][j+2]) {
        b[3] = 1 + dfs(i-1,j+2);
    }
    if(a[i+1][j-2] != 0 && !visit[i+1][j-2]) {
        b[4] = 1 + dfs(i+1,j-2);
    }
    if(a[i+1][j+2] != 0 && !visit[i+1][j+2]) {
        b[5] = 1 + dfs(i+1,j+2);
    }
    if(a[i+2][j-1] != 0 && !visit[i+2][j-1]) {
        b[6] = 1 + dfs(i+2,j-1);
    }
    if(a[i+2][j+1] != 0 && !visit[i+2][j+1]) {
        b[7] = 1 + dfs(i+2,j+1);
    }
    visit[i][j] = 0;
    return maxval(b);
}
int main() {
    int c = 0;
    while(1) {
        c++;
        cnt1 = 0;
        cnt2 = 0;
        scanf("%d",&n);
        if( n == 0)
            break;
        memset(a,0,sizeof(a));
        for(int i = 2;i < n+2;i++) {
            scanf("%d%d",&x,&y);
            cnt2 += y;
            for(int j = x+2;j < x+y+2;j++)
                a[i][j] = 1;
        }
        for(int i = 2; i < 15; i++) {
          if(a[2][i] == 1) {
            x = 2;
            y = i;
            break;
          }
        }
        memset(visit,0,sizeof(visit));
        cnt1 = dfs(x,y);
       // printf("%d %d\n", cnt1,cnt2 );
        if( (cnt2-cnt1-1) == 1)
            printf("Case %d, 1 square can not be reached.\n",c);
        else
            printf("Case %d, %d squares can not be reached.\n",c,cnt2-cnt1-1);

    }
}

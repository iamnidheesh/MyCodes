#include<bits/stdc++.h>
using namespace std;
int m,r,c;
long int dm,ans;
char a[110][110];
long int dis[110][110];
queue < pair < int, int> > q;
void bfs(int i ,int j) {
    int x,y;
    q.push(make_pair(i,j));
    dis[i][j] = 0;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(a[x][y] == 'S') {
            ans = ans + 60 + 2*dis[x][y];
            dm = max(dm,dis[x][y]);
        }
        if(x != 0 && (dis[x-1][y] == -1) && (a[x-1][y] != '#')) {
            q.push(make_pair(x-1,y));
            dis[x-1][y] = 1 + dis[x][y];
        }
        if( x != r-1 && (dis[x+1][y] == -1) && (a[x+1][y] != '#')) {
            q.push(make_pair(x+1,y));
            dis[x+1][y] = 1 + dis[x][y];
        }
        if( y != 0 && (dis[x][y-1] == -1) && (a[x][y-1] != '#' )) {
            q.push(make_pair(x,y-1));
            dis[x][y-1] = 1 + dis[x][y];
        }
        if( y != c-1 && (dis[x][y+1] == -1) && (a[x][y+1] != '#')) {
            q.push(make_pair(x,y+1));
            dis[x][y+1] = 1 + dis[x][y];
        }
    }
}
int main() {

    scanf("%d",&m);
    int flag;
    while(m--) {
        scanf("%d%d",&r,&c);
        dm = 0;
        ans = 0;
        flag = 0;
        for(int i = 0;i < r;i++)
            scanf("%s",a[i]);
        memset(dis,-1,sizeof(dis));
        for(int i = 0;i < r;i++) {
            for(int j = 0;j < c;j++)
                if(a[i][j] == 'C') {
                    bfs(i,j);
                    flag = 1;
                    break;
                }
            if(flag)
                break;
        }
        printf("%ld\n",ans-dm);
    }
}

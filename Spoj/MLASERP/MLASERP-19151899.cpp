#include<bits/stdc++.h>
using namespace std;
int w,h;
char a[110][110];
queue < pair <int,int> > q;
int dis[110][110];

int modbfs(int i ,int j,int k,int l) {
    int x,y;
    q.push(make_pair(i,j));
    dis[i][j] = 0;
    int u,v;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        u = x;
        v = y;
        while(u+1 < h && a[u+1][y] != '*') {
            if(dis[u+1][y] > dis[x][y] + 1) {
                dis[u+1][y] = 1 + dis[x][y];
                q.push(make_pair(u+1,y));
            }
            u++;
        }

        u = x;

         while(u-1 >= 0 && a[u-1][y] != '*') {
            if(dis[u-1][y] > dis[x][y] + 1) {
                dis[u-1][y] = 1 + dis[x][y];
                q.push(make_pair(u-1,y));
            }
            u--;
        }

       while( v+1 < w && a[x][v+1] != '*') {
            if(dis[x][v+1] > dis[x][y] + 1) {
                dis[x][v+1] = 1 + dis[x][y];
                q.push(make_pair(x,v+1));
            }
            v++;
       }
       v = y;
        while( v-1 >= 0 && a[x][v-1] != '*') {
            if(dis[x][v-1] > dis[x][y] + 1) {
                dis[x][v-1] = 1 + dis[x][y];
                q.push(make_pair(x,v-1));
            }
            v--;
       }

    }
    return dis[k][l]-1;
}
int main() {

    scanf("%d%d",&w,&h);
    for(int i = 0;i < h;i++)
        scanf("%s",a[i]);
    vector < pair <int,int> > sd;
    for(int i = 0;i < h;i++)
        for(int j = 0;j < w;j++) {
            if(a[i][j] == 'C')
                sd.push_back(make_pair(i,j));
        }
    for(int i = 0;i < h;i++)
        for(int j = 0;j < w;j++)
            dis[i][j] = INT_MAX;
    printf("%d",modbfs(sd[0].first,sd[0].second,sd[1].first,sd[1].second));

}

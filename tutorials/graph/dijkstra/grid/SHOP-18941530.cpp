#include<bits/stdc++.h>
using namespace std;
int w,h;
char a[30][30];
int dis[30][30];
vector <pair < int,pair<int,int> > > v[30][30];
int dij(pair <int,int> s, pair <int,int> d) {
    priority_queue < pair<int,pair <int,int> > , vector < pair<int,pair <int,int> > >,greater < pair<int,pair <int,int> > > > pq;
    pq.push(make_pair(0,s));
    dis[s.first][s.second] = 0;
    pair<int,int> u;
    while(!pq.empty()) {

        u = (pq.top()).second;
        pq.pop();
        for( vector <pair<int,pair <int,int> > >:: iterator it = v[u.first][u.second].begin(); it != v[u.first][u.second].end();it++) {
            if(dis[u.first][u.second] + it->first < dis[(it->second).first][(it->second).second]) {
                dis[(it->second).first][(it->second).second] = dis[u.first][u.second] + it->first;
                pq.push(make_pair(dis[(it->second).first][(it->second).second],it->second));
            }
        }
        //printf("hello\n");
       // if(u == d)
         //   break;
    }
}
int main() {

    while(1) {
        scanf("%d%d",&w,&h);
        if(w == 0)
            break;
        for(int i = 0;i < h;i++) {
            scanf("%s",a[i]);
        }
        pair <int,int> s;
        pair <int,int> d;
        for(int i = 0;i < h;i++)
            for(int j = 0;j < w;j++) {
                v[i][j].clear();
                dis[i][j] = 1000000;
                if(a[i][j] == 'S') {
                    s = make_pair(i,j);
                    a[i][j] = '0';
                }
                if(a[i][j] == 'D') {
                    d = make_pair(i,j);
                    a[i][j] = '0';
                }
            }
        for(int i = 0;i < h;i++)
            for(int j = 0;j < w;j++) {
                for(int x = i-1;x <= i+1;x += 2) {
                        int y = j;
                        if(x >= 0 && x < h && y >= 0 && y < w) {
                            if(a[x][y] != 'X') {
                                v[i][j].push_back(make_pair(a[x][y] - '0',make_pair(x,y)));
                               // printf("hello\n");
                            }
                        }
                }
                for(int y = j-1;y <= j+1;y += 2) {
                        int x = i;
                        if(x >= 0 && x < h && y >= 0 && y < w) {
                            if(a[x][y] != 'X') {
                                v[i][j].push_back(make_pair(a[x][y] - '0',make_pair(x,y)));
                               // printf("hello\n");
                            }
                        }
                }
            }
        dij(s,d);
        printf("%d\n",dis[d.first][d.second]);
    }

    return 0;
}

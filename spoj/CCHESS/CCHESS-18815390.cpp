#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
vector <pair < int,pair<int,int> > > v[8][8];
priority_queue < pair<int,pair <int,int> > , vector < pair<int,pair <int,int> > >,greater < pair<int,pair <int,int> > > > pq;
int dis[8][8];
int dij() {

    pq.push(make_pair(0,make_pair(a,b)));
    dis[a][b] = 0;
    pair<int,int> u,e;
    e = make_pair(c,d);
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
        if(u == e)
            break;
    }
}
int main() {

    for(int i = 0;i <= 7;i++)
        for(int j = 0;j <= 7;j++) {
                for(int k = -1;k <= 1;k+=2)
                    for(int l = -2; l <= 2;l+=4) {
                        if((i+l) >= 0 && (i+l) <= 7 &&(j+k) >= 0 && (j+k) <= 7)
                            v[i][j].push_back(make_pair(i*(i+l)+j*(j+k),make_pair(i+l,j+k)));
                        if((i+k) >= 0 && (i+k) <= 7 &&(j+l) >= 0 && (j+l) <= 7)
                            v[i][j].push_back(make_pair(i*(i+k)+j*(j+l),make_pair(i+k,j+l)));
                    }
    }
    while(scanf("%d%d%d%d",&a,&b,&c,&d) != -1) {

        for(int i = 0;i <= 7;i++)
            for(int j = 0;j <= 7;j++) {
                dis[i][j] = 10000000;
            }
        pq = priority_queue < pair<int,pair <int,int> > , vector < pair<int,pair <int,int> > >,greater < pair<int,pair <int,int> > > > ();
        dij();
        if(dis[c][d] == 10000000)
            printf("-1\n");
        else
            printf("%d\n",dis[c][d]);
    }
}


#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d;
char x[3],y[3];
vector <pair < int,pair<int,int> > > v[9][9];
priority_queue < pair<int,pair <int,int> > , vector < pair<int,pair <int,int> > >,greater < pair<int,pair <int,int> > > > pq;
int dis[9][9];
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

    for(int i = 1;i <= 8;i++)
        for(int j = 1;j <= 8;j++) {
                for(int k = -1;k <= 1;k+=2)
                    for(int l = -2; l <= 2;l+=4) {
                        if((i+l) >= 1 && (i+l) <= 8 &&(j+k) >= 1 && (j+k) <= 8)
                            v[i][j].push_back(make_pair(1,make_pair(i+l,j+k)));
                        if((i+k) >= 1 && (i+k) <= 8 &&(j+l) >= 1 && (j+l) <= 8)
                            v[i][j].push_back(make_pair(1,make_pair(i+k,j+l)));
                    }
    }
    cin>>t;
    while(t--) {
        for(int i = 1;i <= 8;i++)
            for(int j = 1;j <= 8;j++) {
                dis[i][j] = 10000000;
            }
        pq = priority_queue < pair<int,pair <int,int> > , vector < pair<int,pair <int,int> > >,greater < pair<int,pair <int,int> > > > ();
        scanf("%s%s",x,y);
        a = x[0] - 'a' + 1;
        b = x[1] - '0';
        c = y[0] - 'a' + 1;
        d = y[1] - '0';
        dij();
        if(dis[c][d] == 10000000)
            printf("-1\n");
        else
            printf("%d\n",dis[c][d]);
    }
}

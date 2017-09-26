#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
typedef pair<int,int> ii;
//thanks :) to codeforces blog : http://codeforces.com/blog/entry/45897
int n,t;
int tim[55][55];
int toll[55][55];
int dis[55][1001];

struct State
{
    int v, t, d;
    State() {}
    State(int a, int b, int c) { v = a; t = b; d = c; }
    bool operator>(const State &s) const { return d > s.d; }
};

void dijstra() {

    priority_queue< State,vector<State>,greater<State> > pq;
    pq.push(State(0,t,0));
    while(!pq.empty()) {
        State s = pq.top();
        pq.pop();
        if(dis[s.v][s.t] < s.d)
            continue;
        dis[s.v][s.t] = s.d;
        for(int i = 0;i < n;i++) {
            if(i == s.v)
                continue;
            int w = toll[s.v][i];
            if(s.t - tim[s.v][i] >= 0) {
                if(dis[i][s.t-tim[s.v][i]] > s.d + w) {
                    dis[i][s.t-tim[s.v][i]] = s.d + w;
                    pq.push(State(i,s.t-tim[s.v][i],s.d + w));
                }
            }
        }
    }
}

int main() {
    
    while(1) {
        scanf("%d%d",&n,&t);
        if(n == 0)
            break;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                scanf("%d",&tim[i][j]);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                scanf("%d",&toll[i][j]);
        for(int i = 0;i < n;i++)
            for(int j = 0;j <= t;j++) {
                dis[i][j] = INF;
            }
        dijstra();
        int tot_toll = INF;
        int tot_time = 0;
        for(int i = 0;i <= t;i++) {
            if(tot_toll > dis[n-1][i]) {
                tot_toll = dis[n-1][i];
                tot_time = t-i;
            }
        }
        printf("%d %d\n",tot_toll,tot_time);
    }

}
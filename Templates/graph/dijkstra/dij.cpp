#include <bits/stdc++.h>
using namespace std;
#define pp pair <int,int>

int dij(vector < pp > * v,int s,int * dis) {
    priority_queue < pp , vector < pp >,greater < pp > > pq;
    pq.push(make_pair(0,s));
    dis[s] = 0;
    int u;
    while(!pq.empty()) {

        u = (pq.top()).second;
        pq.pop();
        for( vector < pp > :: iterator it = v[u].begin(); it != v[u].end();it++) {
            if(dis[u] + it->first < dis[it->second]) {
                dis[it->second] = dis[u] + it->first;
                pq.push(make_pair(dis[it->second],it->second));
            }
        }
    }
}

int main() {

}
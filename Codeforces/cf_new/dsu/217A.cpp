#include <bits/stdc++.h>
using namespace std;
int n,x,y;
vector <pair<int,int> > v;
pair <int,int> p[1001][1001];
void makeset()
    {
    for(int i = 1;i <= 1000;i++)
        for(int j = 1;j <= 1000;j++)
            p[i][j] = make_pair(i,j);
}
pair <int,int> find_par(pair <int,int> x)
    {
    if(p[x.first][x.second] == x)
        return x;
    p[x.first][x.second] = find_par(p[x.first][x.second]);
    return p[x.first][x.second];
}
void uni(pair <int,int> x,pair <int,int> y)
    {
    pair <int,int> px = find_par(x);
    pair <int,int> py = find_par(y);
    if(px != py) {
        p[px.first][px.second] = py;
    }
}
int main() {
    makeset();
    cin>>n;
    for(int i = 0;i < n;i++) {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++) {
            if(i != j) {
                if(v[i].first == v[j].first || v[i].second == v[j].second) {
                    uni(v[j],v[i]);
                }
            }
        }
    set <pair<int,int> > ans;
    for(int i = 0;i < n;i++) {
        ans.insert(find_par(p[v[i].first][v[i].second]));
    }

    cout<<ans.size()-1;
}
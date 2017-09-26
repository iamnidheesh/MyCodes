#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
pair <int,int> p[1005][1005];
set <pair <int,int> > s;
int n,m;
void makeset()
    {
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
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

    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        scanf("%s",a[i]+1);
    makeset();
    for(int i = 1;i <= n;i++)
        for(int j =1;j <= m;j++) {
            if(a[i][j] == 'S') {
                    if(find_par(make_pair(i,j)) != find_par(make_pair(i+1,j))) {
                        uni(make_pair(i,j),make_pair(i+1,j));
                        //s.insert(find_par(make_pair(i,j)));
                    }
            }
            if(a[i][j] == 'N') {
                    if(find_par(make_pair(i,j)) != find_par(make_pair(i-1,j))) {
                        uni(make_pair(i,j),make_pair(i-1,j));
                        //s.insert(find_par(make_pair(i,j)));
                    }
            }
            if(a[i][j] == 'E') {
                    if(find_par(make_pair(i,j)) != find_par(make_pair(i,j+1))) {
                        uni(make_pair(i,j),make_pair(i,j+1));
                        //s.insert(find_par(make_pair(i,j)));
                    }
            }
            if(a[i][j] == 'W') {
                    if(find_par(make_pair(i,j)) != find_par(make_pair(i,j-1))) {
                        uni(make_pair(i,j),make_pair(i,j-1));
                        //s.insert(find_par(make_pair(i,j)));
                    }
            }
        }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            s.insert(find_par(make_pair(i,j)));
    printf("%d",s.size());
}

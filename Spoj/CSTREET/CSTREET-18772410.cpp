#include <bits/stdc++.h>
using namespace std;
struct edge {
    int w;
    int u;
    int v;
};
struct edge st[300005];
int p[1010];
int t,cost,n,m;
void makeset(int n)
    {
    for(int i = 1;i <= n;i++)
          p[i] = i;
}
int find_par(int x)
    {
    if(p[x] == x)
        return x;
    p[x] = find_par(p[x]);
    return p[x];
}
void uni(int x,int y)
    {
    int px = find_par(x);
    int py = find_par(y);
    if(px != py) {
        p[px] = py;
    }
}
int cmp(struct edge a,struct edge b)
    {
    if(a.w < b.w)
         return 1;
    else
        return 0;
}
int main() {
        int ans = 0;
        cin>>t;
        while(t--) {
            scanf("%d%d%d",&cost,&n,&m);
            ans = 0;
        for(int i = 0;i < m;i++)
            scanf("%d%d%d",&(st[i].u),&(st[i].v),&(st[i].w));
        makeset(n);
        sort(st,st+m,cmp);
        for(int i = 0;i < m;i++) {

            if(find_par(st[i].u) != find_par(st[i].v)) {
                ans += st[i].w;
                uni(st[i].u,st[i].v);
            }
        }
            printf("%d\n",ans*cost);
        }
}

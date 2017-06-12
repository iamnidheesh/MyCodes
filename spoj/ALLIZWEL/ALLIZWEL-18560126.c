#include<bits/stdc++.h>
using namespace std;
int t,R,C;
char s[110][110];
int mark[110][110];
char a[12] = {'A','L','L','I','Z','Z','W','E','L','L','@','\0'};
int cal(int x,int y,int k) {
    if(k == 9)
        return 1;
    else if(x == R+1 || y == C+1 || y == 0 || x == 0)
        return 0;
    int ans = 0;
    mark[x][y] = 1;
    if(s[x+1][y] == a[k+1] && !mark[x+1][y])
        ans = ans || cal(x+1,y,k+1);
    if(s[x+1][y+1] == a[k+1] && !mark[x+1][y+1])
        ans = ans || cal(x+1,y+1,k+1);
    if(s[x+1][y-1] == a[k+1] && !mark[x+1][y-1])
        ans = ans || cal(x+1,y-1,k+1);
    if(s[x][y+1] == a[k+1] && !mark[x][y+1])
        ans = ans || cal(x,y+1,k+1);
    if(s[x][y-1] == a[k+1] && !mark[x][y-1])
        ans = ans || cal(x,y-1,k+1);
    if(s[x-1][y] == a[k+1] && !mark[x-1][y])
        ans = ans || cal(x-1,y,k+1);
    if(s[x-1][y-1] == a[k+1] && !mark[x-1][y-1])
        ans = ans || cal(x-1,y-1,k+1);
    if(s[x-1][y+1] == a[k+1] && !mark[x-1][y+1])
        ans = ans || cal(x-1,y+1,k+1);
    if(ans == 0)
        mark[x][y] = 0;
    return ans;

}
int main() {
    cin>>t;
    int flag;
    while(t--) {
        flag = 0;
        scanf("%d%d",&R,&C);
        memset(mark,0,sizeof(mark));
        for(int i = 1;i <= R;i++)
            scanf("%s",1+s[i]);
        for(int i = 1;i <= R;i++) {
            for(int j = 1;j <= C;j++) {
                if(flag == 1)
                    break;
                if(s[i][j] == 'A') {
                    flag = cal(i,j,0);
                }
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

#include<bits/stdc++.h>
using namespace std;
int a,b,x,y,ans;
int main() {
    while(1) {
        scanf("%d%d",&a,&b);
        if(a == -1)
            break;
        x = min(a,b);
        y = max(a,b);
        if(x == 0)
            ans = y;
        else {
            if(y%(x+1) == 0)
                ans = y/(x+1);
            else
                ans = y/(x+1) + 1;
        }
        printf("%d\n",ans);
    }
}

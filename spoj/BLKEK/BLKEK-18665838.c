#include<bits/stdc++.h>
using namespace std;
int t;
char s[2010];
pair <int,int> p[2010];
int main() {
    int c,n,ans,m,j;
    scanf("%d",&t);
    while(t) {

        j = 0;
        c = 0;
        n = 0;
        ans = 0;
        scanf("%s",s);
        for(int i = 0;s[i] != '\0';i++) {
            if(s[i] == 'K')
                c++;
            if(s[i] == 'E') {
                p[j].first = c;
                j++;
            }
            n++;
        }
        c = 0;
        m = j;
        j--;
        for(int i = n-1;i >= 0 ;i--) {
            if(s[i] == 'K')
                c++;
            if(s[i] == 'E') {
                p[j].second = c;
                j--;
            }
        }
        for(int i = 0;i < m;i++) {
            ans += p[i].first*p[i].second;
        }
        printf("%d\n",ans);
        t--;
    }


    return 0;
}

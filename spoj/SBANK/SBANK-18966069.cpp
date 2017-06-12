#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    scanf("%d",&t);
    char s[100];
    while(t--) {
        map <string,int> m;
        scanf("%d\n",&n);
        while(n){
            n--;
            gets(s);
            m[(string)s]++;
        }
        for(map <string,int> :: iterator it = m.begin();it != m.end();it++)
            printf("%s%d\n",(it->first).c_str(),it->second);
        if(t > 0)
            printf("\n");
    }
}

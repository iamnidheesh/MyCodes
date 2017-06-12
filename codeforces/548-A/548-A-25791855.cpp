#include<bits/stdc++.h>
using namespace std;
int k;
char s[1010];
bool check(char * s,int l,int u) {
    int flag = 1;
    while(l < u) {
        if(s[l] == s[u]) {
            l++;
            u--;
        }
        else {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main() {
    int flag = 1;
    scanf("%s",s);
    cin>>k;
    int len = strlen(s);
    int plen = len/k;
    if(len%k != 0)
        flag = 0;
    else
    for(int i = 0;i < len;i += plen) {
        if(!check(s,i,i+plen-1)) {
            flag = 0;
            break;
        }
    }
    flag ? printf("YES") : printf("NO");

}
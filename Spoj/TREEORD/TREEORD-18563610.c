#include<bits/stdc++.h>
using namespace std;
int n;
int in[8010];
int pre[8010];
int post[8010];
int pre_post[8010];
int pos = 0;
int search(int l,int u,int k) {
    for(int i = l;i <= u;i++)
        if(in[i] == pre[k])
            return i;
}
void find_post(int l,int u,int k) {

    if(u < l)
        return;
    if(u == l) {
            if(pos != 0 && pre_post[pos-1] == in[u])
                pre_post[pos++] = in[u];

    }
    int m = search(l,u,k);
    find_post(l,m-1,k+1);
    find_post(m+1,u,k+m-l+1);
    pre_post[pos++] = in[m];
}
int main() {
    cin>>n;
    for(int i = 0;i < n;i++) {
        scanf("%d",&pre[i]);
    }
    for(int i = 0;i < n;i++) {
        scanf("%d",&post[i]);
    }
    for(int i = 0;i < n;i++) {
        scanf("%d",&in[i]);
    }
    int flag = 1;
    find_post(0,n-1,0);
    for(int i = 0;i < n;i++)
        if(pre_post[i] == post[i])
            continue;
        else
            flag = 0;
    if(flag)
        printf("yes");
    else
        printf("no");
}

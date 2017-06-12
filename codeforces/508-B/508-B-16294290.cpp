#include<bits/stdc++.h>
using namespace std;
int main() {
    char n[100001];
    scanf("%s",n);
    int i,j=0,l=strlen(n)-1;
    pair<char,int> p[100001];
    for(i=0;n[i]!='\0';i++) {
        if(n[i]%2==0) {
            p[j].first=n[i];
            p[j].second=i;
            j++;
        }
    }
    for(i=0;i<j-1;i++) {
        if(p[i].first<n[l])
            break;
        else
            continue;
    }
    if(j==0)
        printf("-1");
    else {
        swap(n[p[i].second],n[l]);
        printf("%s",n);
    }
    return 0;
}
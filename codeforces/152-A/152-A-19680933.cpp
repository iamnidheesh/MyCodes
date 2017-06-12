#include<bits/stdc++.h>
using namespace std;
int a[101];
char s[101][101];
int main() {
    int n,m;
    char max_m = '0';
    cin>>n>>m;
    for(int i = 0;i < n;i++)
        scanf("%s",s[i]);
    for(int i = 0;i < m;i++) {
            max_m = '0';
        for(int j = 0;j < n;j++) {
            if(s[j][i] > max_m) {
                max_m = s[j][i];
            }
        }
        for(int k = 0;k < n;k++) {
            if(s[k][i] == max_m)
                a[k] = 1;
        }
    }
    int c = 0;
    for(int i = 0;i < n;i++) {
        if(a[i] == 1)
            c++;
    }
    cout<<c;


}
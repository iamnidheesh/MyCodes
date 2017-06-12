#include<bits/stdc++.h>
using namespace std;
int main() {
    map <char,int> m;
    char s[1001];
    int k;
    cin>>k;
    scanf("%s",s);
    for(int i = 0;s[i] != '\0';i++)
        m[s[i]]++;
    for(char c = 'a';c <= 'z';c++) {
        if(m[c] != 0 && m[c]%k != 0) {
            cout<<-1;
            return 0;
        }
    }
    for(int i = 0;i < k;i++) {
        for(char c = 'a'; c <= 'z';c++)
            for(int j = 0;j < m[c]/k;j++ )
                cout<<c;
    }
}
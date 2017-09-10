#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char name[100001];
    cin>>n;
    scanf("%s",name);
    int c = 0;
    map <char,int> m;
    if(n <= 26) {
        for(int i = 0;i < n;i++) {
            if(m[name[i]])
                c++;
            else
                m[name[i]]++;
        }
        cout<<c;
    }
    else
        cout<<-1;
    return 0;
}
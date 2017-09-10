#include<bits/stdc++.h>
using namespace std;
int main() {
    map <string,string> st;
    string f,s;
    int n,m;
    cin>>n>>m;
    while(m--) {
     cin>>f>>s;
     if(f.size()>s.size())
        st[f]=s;
     else
        st[f]=f;
    }
    while(n--) {
        cin>>f;
        cout<<st[f]<<" ";
    }
    return 0;
    }
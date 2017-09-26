#include<bits/stdc++.h>
using namespace std;
#define llu long long unsigned int
map <char,llu> co;
int main() {
    string s;
    cin>>s;
    map <char,int> m;

    int j = 0;
    for(char c = '0';c <='9';c++)
        {m[c] = j;j++;}
    for(char c = 'A';c <='Z';c++)
        {m[c] = j;j++;}
    for(char c = 'a';c <='z';c++)
        {m[c] = j;j++;}

    m['-'] = 62;
    m['_'] = 63;
for (std::map<char,int>::iterator it=m.begin(); it!=m.end(); ++it)
    for (std::map<char,int>::iterator it1=m.begin(); it1!=m.end(); ++it1)
        for (std::map<char,int>::iterator it2=m.begin(); it2!=m.end(); ++it2)
        {
            if(( (it1->second)&(it2->second) )== it->second)
                    co[it->first] +=1;
        }

    llu ans = 1;
    int n = s.size();
    for(int i = 0;i < n;i++) {
            ans = ans*co[s[i]];
            ans = ans%(1000000007);

    }
    cout<<ans;
    return 0;
    }
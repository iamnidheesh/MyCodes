#include<bits/stdc++.h>
using namespace std;
map <char,int> m;
vector <char> v,v1;
int main() {
    char s[50005];
    scanf("%s",s);
    int k,flag = 0,pos;
    int n = strlen(s);
    for(int i = 0;i < n-25;i++) {
        k = 0;
        for(int j = i;j < i+26;j++) {
            if(s[j] != '?')
                m[s[j]]++;
            else
                k++;
        }
     //   cout<<m.size()<<endl;
        if(m.size() + k == 26) {
                pos = i;
            for(map <char,int> :: iterator it = m.begin(); it != m.end();it++)
                    v.push_back(it->first);
                for(char c = 'A'; c <= 'Z';c++)
                    if(!binary_search(v.begin(),v.end(),c))
                        v1.push_back(c);

                flag = 1;
                break;
        }
        m.clear();
    }
    k = 0;
    if(flag == 1) {
        for(int i = pos;i < pos + 26;i++) {
            if(s[i] == '?') {
                s[i] = v1[k];
                k++;
            }
        }
    }
    else {
        cout<<-1<<endl;
        return 0;
    }
    for(int i = 0;s[i] != '\0';i++)
        if(s[i] == '?')
            printf("A");
        else
            printf("%c",s[i]);
    return 0;
}
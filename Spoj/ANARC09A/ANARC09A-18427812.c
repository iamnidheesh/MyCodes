#include<bits/stdc++.h>
using namespace std;
char s[2010];
int main() {
    int c = 0;
    while(1) {
        c++;
        stack <char> st;
        int ans = 0;
        scanf("%s",s);
        if(s[0] == '-')
            break;
        for(int i = 0;s[i] != '\0';i++) {
            if(st.empty()) {
                if(s[i] == '{');
                else
                    ans++;
                st.push('{');
                continue;
            }
            if(st.top() == '{' && s[i] == '}')
                st.pop();
            else if(st.top() == '{' && s[i] == '{')
                st.push(s[i]);
            }
            ans += st.size()%2 + st.size()/2;
            printf("%d. %d\n",c,ans);
    }

    return 0;
}

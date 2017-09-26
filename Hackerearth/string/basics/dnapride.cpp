#include <bits/stdc++.h>
using namespace std;
int t,n;
char s[1000001];
char m[26];
int main()
{
    cin>>t;
    m['A'-'A'] = 'T';
    m['T' - 'A'] = 'A';
    m['G' - 'A'] = 'C';
    m['C' - 'A'] = 'G';
    m['U'-'A'] = 0;
    while(t--) {
        cin>>n;
        scanf("%s",s);
        int flag = 1;
        for(int i = 0;i < n;i++) {
            if(s[i] == 'U') {
                flag = 0;
                printf("Error RNA nucleobases found!\n");
                break;
            }
            else {
                s[i] = m[s[i]-'A'];
            }
        }
        if(flag)
            printf("%s\n",s);
    }
    return 0;
}

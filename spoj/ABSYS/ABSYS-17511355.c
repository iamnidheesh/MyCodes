#include<bits/stdc++.h>
using namespace std;
char s[5][15];
int main() {
    int t,flag;
    cin>>t;
    while(t--) {
        flag = -1;
        for(int i = 0;i < 5;i++)
            scanf("%s",s[i]);
        for(int i = 0;i < 5;i += 2) {
            for(int j = 0;s[i][j] != '\0';j++)
                if(s[i][j] == 'm') {
                    flag = i;
                    break;
                }
            if(flag == i)
                break;
        }
        if(flag == 0)
            printf("%d %s %s %s %s\n",atoi(s[4])- atoi(s[2]),s[1],s[2],s[3],s[4]);
        else if(flag == 2)
            printf("%s %s %d %s %s\n",s[0],s[1],atoi(s[4]) - atoi(s[0]),s[3],s[4] );
        else
            printf("%s %s %s %s %d\n",s[0],s[1],s[2],s[3],atoi(s[0]) + atoi(s[2]));
    }
}

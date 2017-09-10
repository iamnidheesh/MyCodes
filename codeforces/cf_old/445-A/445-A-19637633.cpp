#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    char c[101][101];
    cin>>n>>m;
    for(int i = 0; i < n;i++) {
        scanf("%s",c[i]);
    }
    for(int i = 0;i < n;i++) {
        if(i%2 == 0) {
                for(int j = 0;j < m;j++) {
                    if(c[i][j] == '-') {
                        cout<<"-";
                        continue;
                    }
                    else if(j%2 == 0)
                        cout<<"B";
                    else
                        cout<<"W";
                }
        }
        else {
                 for(int j = 0;j < m;j++) {
                    if(c[i][j] == '-') {
                        cout<<"-";
                        continue;
                    }
                    else if(j%2 != 0)
                        cout<<"B";
                    else
                        cout<<"W";

                }
        }
        cout<<endl;
    }

return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    int x,bx,y,by;
    double sx=0,sy=0,n;
    cin>>x>>bx;
    while(x--) {
        cin>>n;
        sx=sx+n*pow(bx,x);
    }
    cin>>y>>by;
    while(y--) {
        cin>>n;
        sy=sy + n*pow(by,y);
    }
    sx>sy?cout<<">":sx==sy?cout<<"=":cout<<"<";
    return 0;
}
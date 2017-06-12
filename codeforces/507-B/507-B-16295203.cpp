#include<bits/stdc++.h>
using namespace std;
int main() {
    int r,x,y,x1,y1;
    cin>>r>>x>>y>>x1>>y1;
    long double d=sqrt(pow(x-x1,2)+pow(y-y1,2));
    if(d/(2*r)-(int)d/(2*r)>0.0)
        cout<<((int)d/(2*r)+1);
    else
        cout<<(int)d/(2*r);
    return 0;
}
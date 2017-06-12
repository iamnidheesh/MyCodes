#include<bits/stdc++.h>
#define llu long long unsigned int
#define ll long long int;
using namespace std;
int main() {
    int n;
    int a,b;
    cin>>a>>b>>n;
    double m = 100000.0000,s;
    double z;
    int x,y,v;
    while(n--) {
        cin>>x>>y>>v;
        z = 1.0*(pow(x-a,2) + pow(y -b,2) );
        s = sqrt(z)/v;
        if(m > s)
            m = s;
    }
    printf("%.20lf",m);
}
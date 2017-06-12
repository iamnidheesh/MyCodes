#include<bits/stdc++.h>
#define llu long long unsigned int
#define ll long long int;
using namespace std;
vector <long int> v;
int main() {
    long int n,q,x,m;
    cin>>n;
    for(long int i = 0;i < n;i++) {
            cin>>x;
        v.push_back(x);
    }
    cin>>q;
    sort(v.begin(),v.end());
    vector<long int>:: iterator low;
    for(long int i = 0;i < q;i++) {
            cin>>m;
        cout<<upper_bound(v.begin(),v.end(),m) - v.begin()<<endl;


    }


}
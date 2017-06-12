#include<bits/stdc++.h>
using namespace std;
int main() {
    pair<long int,long int>p[5010];
    int n;
    long int last=1;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
    sort(p,p+n);
    for(int i=0;i<n;i++) {
         p[i].second>=last?last=p[i].second:last=p[i].first;
    }
    cout<<last;
    return 0;
    }
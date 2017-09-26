#include<bits/stdc++.h>
using namespace std;
pair <int ,int> p[1000000];
int main() {

    int t;
    int n;
    int st;
    int en;
    int m;
    int c;
    cin>>t;
    while(t--) {
        m = 0;
        c = 1;
        cin>>n;
        for(int i = 0;i < n;i++) {
            cin>>p[i].second>>p[i].first;
        }
        sort(p,p+n);
        int k = 0;
        for(int j = 1;j < n;j++) {
            if(p[k].first <= p[j].second) {
                c++;
                k = j;
            }
        }
        cout<<c<<endl;

    }
}

#include<bits/stdc++.h>
using namespace std;
#define llu long long unsigned int
llu a[1000001];
int main() {
    int n;
    llu k,h,t = 0;
    cin>>n>>h>>k;
    llu s = h;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    for(int i = 0;i < n;) {
        while(s >= a[i] && i < n) {
            s = s-a[i];
            i++;
        }
        if(i == n) {
            t = t + (h-s)/k;
            if((h-s)%k != 0)
                t++;

        }
        else  {
            t = t + (h-s)/k;
            s = s +(h-s) - (h-s)%k;
            if(s < a[i]) {
                t++;
                s = h;
            }
            //cout<<s<<endl;
        }


    }
    cout<<t;
    return 0;
    }
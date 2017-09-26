#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    vector < float > v;
    float sum = 0.0;
    for(int i = 0;i < 25;i++) {
        sum = sum + 60*((1.0*12)/11);
        v.push_back(sum);
    }
    int sh,sm,eh,em,ans;
    char c;
    while(t--) {
        scanf("%d%c%d%d%c%d",&sh,&c,&sm,&eh,&c,&em);
        ans = lower_bound(v.begin(),v.end(),eh*60 + em) - upper_bound(v.begin(),v.end(),sh*60 + sm);
        if(eh == 12 && em == 00)
            ans++;
        printf("%d\n",ans);
    }
}

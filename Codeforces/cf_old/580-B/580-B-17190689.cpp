#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,i,j;
    long int d,m,s;
    unsigned long long int ans,curr,sum = 0;
    cin>>n>>d;
    pair<long int ,long int > a[100001];
    for(int i=0;i<n;i++) {
        cin>>m>>s;
        a[i].first=m;
        a[i].second=s;
    }
    sort(a,a+n);
    curr = a[0].second;
    ans = curr;
    i =0 ;
    j = 0;
    for(i = 0;i<n;i++) {
            sum+=a[i].second;
            while(a[i].first - a[j].first>=d)
            {
                        sum-=a[j].second;
                        j++;
            }
            ans = max(ans,sum);
        }
        cout<<ans<<endl;

    }
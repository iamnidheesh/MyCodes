#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
    int n,k,c = 0;
    cin>>n>>k;
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int l = 0,r = 1;
    while(r != n ) {
        if(a[r] - a[l] < k)
            r++;
        else if(a[r] - a[l] > k)
            l++;
        else {
            c++;
            l++;
            r++;
        }
    }
    printf("%d",c);
}

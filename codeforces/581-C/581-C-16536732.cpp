#include<bits/stdc++.h>
int cmpt(const void * a,const void *b)
{
    return *(int*)b-*(int *)a;
}
using namespace std;
int main() {
    int n,k,x,r=0,flag;
    cin>>n>>k;
    int a[100001];
    for( int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        r=r+a[i]/10;
        a[i]%=10;
    }
    qsort(a,n,sizeof(int),cmpt);
        for( int i = 0; i< n ; i++) {
            if(k >= 10-a[i]) {
                k-=10-a[i];
                r=r + 1;
            }
        }
    r=r+ k/10;
    r=min(r,n*10);
    cout<<r;
    return 0;
    }
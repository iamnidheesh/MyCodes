#include<bits/stdc++.h>
using namespace std;
long int a[10010],b[10010];
long int p,q;
int main() {
    int n,m;
    while(1) {
        cin>>m;
        long int s = 0,sa,sb;
        p = 0,q = 0;
        if(m == 0)
            break;
        for(int i = 0;i < m;i++)
            scanf("%ld",&a[i]);
        cin>>n;
        for(int i = 0;i < n;i++)
            scanf("%ld",&b[i]);
        a[m]  = 20000;
        b[n] = 20000;
        m++;
        n++;
        while(p < m && q < n) {
            sa = a[p],sb = b[q];
            while(a[p] != b[q] && p < m && q < n) {
                if(a[p] > b[q]) {
                    q++;
                    sb += b[q];
                }
                else {
                    p++;
                    sa += a[p];
                }
            }
           // printf("sa = %ld\n sb = %ld\n",sa,sb);
            p++;
            q++;
            s += max(sa,sb);
        }
        printf("%ld\n",s - 20000);

    }
}

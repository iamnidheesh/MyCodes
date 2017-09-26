#include<bits/stdc++.h>
long int a[1001][1001];
long int d[1001],c[1001];
using namespace std;
int main() {
    int n,sn = 0;
    while(1) {
        sn++;
        long int b = 0,ans = 0;
        scanf("%d",&n);
        if(!n)
            break;
        for(int i = 1;i <= n;i++) {
            d[i] = 0;
            c[i] = 0;
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                scanf("%ld",&a[i][j]);
                b = b + a[i][j];
                d[i] = d[i] + a[i][j];
                c[j] = c[j] + a[i][j];
            }
        }
        int temp;
        for(int i = 1;i <= n;i++) {
            temp = c[i] - d[i];
            if(temp > 0)
                ans = ans + temp;
        }
        printf("%d. %ld %ld\n",sn,b,ans);


    }
}

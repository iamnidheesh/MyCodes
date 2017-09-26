#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main() {
int n,sum,ans,avg;
while(1) {
    sum = 0;
    ans = 0;
    scanf("%d",&n);
    if(n == -1)
        break;
    for(int i = 0;i < n;i++){
         scanf("%d",&a[i]);
         sum = sum + a[i];
    }
    if(sum%n == 0) {
            avg = sum/n;
        for(int i = 0;i < n;i++) {
            if(a[i] < avg)
                ans = ans + avg - a[i];
        }
        printf("%d\n",ans);
    }
    else
        printf("%d\n",-1);
}
}

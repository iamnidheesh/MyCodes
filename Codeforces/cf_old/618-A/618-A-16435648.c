#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[1000000];
    int i=0;
    for(i=0; i<n; i++) {
        a[i]=1;
        while(i>0&&a[i]==a[i-1]) {
            a[i]=0;
            a[i-1]++;
            i--;
            n--;
        }
    }
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    return 0;
}
#include<stdio.h>
int main()
        {
        long long int n,i,k,j,a[100000];
        scanf("%I64d",&n);
        for(i=0;i<n;i++)
                scanf("%I64d",&a[i]);
        for(i=0;a[i]<=a[i+1]&&i!=n-1;i++);
        if(i==n-1||n==1)
                printf("yes\n1 1");
        else
                {for(j=i;a[j]>=a[j+1]&&j!=n-1;j++);
                if(j==n-1&&a[j]>=a[i-1])
                        printf("yes\n%I64d %I64d",i+1,j+1);
                else if(j==n-1&&i==0)
                        printf("yes\n%I64d %I64d",i+1,j+1);
                else if(j==n-1&&a[j]<a[i-1])
                        printf("no");
                else
                        {for(k=j;a[k]<=a[k+1]&&k!=n-1;k++);
                        if(k!=n-1)
                                printf("no");
                        else if(a[j]>=a[i-1]&&a[i]<a[j+1])
                                printf("yes\n%I64d %I64d",i+1,j+1);
                        else
                                printf("no");
                        }
                }
        return 0;
        }
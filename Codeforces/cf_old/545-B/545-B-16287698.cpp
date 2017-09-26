#include<bits/stdc++.h>
int main() {
    char s1[100001];
    char s2[100001];
    char s3[100001];
    int c=0,i;
    scanf("%s",s1);
    scanf("%s",s2);
    for(i=0;s1[i]!='\0';i++) {
        c=c+abs(s1[i]-s2[i]);
        if(s1[i]==s2[i])
            s3[i]=s1[i];
        else if(c%2==0)
            s3[i]=s2[i];
        else if(c%2!=0)
            s3[i]=s1[i];
    }
    s3[i]='\0';
    if(c%2!=0)
        printf("impossible");
    else
        printf("%s",s3);
    return 0;
    }
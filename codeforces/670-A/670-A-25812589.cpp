#include<bits/stdc++.h>
using namespace std;
int n;
int main() {

    cin>>n;
    switch (n%7) {

    case 0: {
        printf("%d %d",(n/7)*2,(n/7)*2);break;
    }
    case 1: {
         printf("%d %d",(n/7)*2,(n/7)*2+1);break;
    }
    case 2: {
         printf("%d %d",(n/7)*2,(n/7)*2+2);break;
    }
    case 3: {
         printf("%d %d",(n/7)*2,(n/7)*2+2);break;
    }
    case 4: {
         printf("%d %d",(n/7)*2,(n/7)*2+2);break;
    }
    case 5: {
         printf("%d %d",(n/7)*2,(n/7)*2+2);break;
    }
    case 6: {
         printf("%d %d",(n/7)*2+1,(n/7)*2+2);break;
    }

    }
}
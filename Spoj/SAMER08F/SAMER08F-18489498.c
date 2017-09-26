#include<bits/stdc++.h>
using namespace std;
unsigned long long int n;
int main() {
    while(1){
        scanf("%llu",&n);
        if(n == 0)
            break;
        printf("%llu\n",(n*(n+1)*(2*n+1))/6);
    }
}

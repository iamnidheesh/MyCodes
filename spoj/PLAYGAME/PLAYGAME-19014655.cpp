#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
int t,n;
int main() {

    cin>>t;
    while(t--) {
        scanf("%llu",&n);
        if(n%3 == 0)
            printf("Ragini\n");
        else
            printf("Hemlata\n");
    }
}

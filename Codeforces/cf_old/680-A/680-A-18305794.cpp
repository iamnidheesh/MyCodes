#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
int c[101];
int main() {
    int a[5],s = 0;
    for(int i = 0;i < 5;i++)
        {cin>>a[i];
            s = s + a[i];
            c[a[i]]++;
        }
    int co = 0;
    int k = 0,l = 0;
    for(int i = 101; i > 0;i--) {
        if(c[i] == 2)
            {k = max(i*2,k);
            }
        else if(c[i] == 3) {
            l = max(i*3,l);
            }
        else if(c[i] > 3)
            l = max(i*3,k);

    }
    cout<<s - max(k,l);







    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
        int n,s=0,d=0,c=1;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int l =0,u=n-1;
        while(n--) {
            if(c==1) {
                if(a[l]>a[u]){
                    s = s+a[l++];
                }
                else s= s+a[u--];
                c=0;
            }
            else {
                if(a[l]>a[u])
                    d= d+ a[l++];
                else
                    d= d+ a[u--];
                c= 1;
            }
        }
        cout<<s<<" "<<d;
        return 0;
    }
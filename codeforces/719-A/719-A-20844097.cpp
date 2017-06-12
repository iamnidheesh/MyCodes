#include<bits/stdc++.h>
using namespace std;
#define llu long long unsigned int;
int a[92];
int main() {
    int flag;
    int n;
    cin>>n;
    for(int i  = 0;i < n;i++)
        cin>>a[i];
    for(int i = 0;i < n-1;i++)
        if(a[i] < a[i+1])
            flag = 1;
        else
            flag = 0;
    if(a[n-1] == 0)
        cout<<"UP"<<endl;
    else if(a[n-1] == 15)
        cout<<"DOWN"<<endl;

    else if(n == 1 )
        cout<<-1<<endl;
    else {
        if(flag )
            cout<<"UP"<<endl;
        else
            cout<<"DOWN"<<endl;

    }




    return 0;
}
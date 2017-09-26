#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
#define ll long long int;
int main() {
    int n;
    cin>>n;
    string h = "I hate";
    string l = "I love";
    for(int i = 1;i <= n;i++) {
        if(i%2 != 0)
            cout<<h+" ";
        else
            cout<<l +" ";
        if(i == n)
            cout<<"it";
        else
            cout<<"that ";
    }

}
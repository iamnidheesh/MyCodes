#include<bits/stdc++.h>
using namespace std;
long int b[200001];
int main() {
    int n;
    cin>>n;
    long long int c = 0;
    for(int i = 0;i < n;i++)
        cin>>b[i];
    for(int i = 0;i < n-1;i++)
        c += abs(b[i] - b[i+1]);
    cout<<c + abs(b[0]);
}
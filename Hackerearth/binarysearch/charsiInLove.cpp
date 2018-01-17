#include <bits/stdc++.h>
using namespace std;
long int n;
vector <long int> v;
int main()
{
    cin>>n;
    int i = 1;
    while(1) {
        if((i*(i+1))/2 > n)
            break;
        v.push_back((i*(i+1))/2);
        i++;
    }
    bool flag = false;
    for(int i = 0;i < v.size();i++) {
        if(binary_search(v.begin(),v.end(),n-v[i])) {
            flag = true;
            break;
        }
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    
    return 0;
}

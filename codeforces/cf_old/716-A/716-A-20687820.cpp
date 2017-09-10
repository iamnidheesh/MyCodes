#include<bits/stdc++.h>
using namespace std;
stack < long int > s;
int main() {
    long int n,c,x;
    cin>>n>>c;
    for(long int i = 0;i < n;i++ ) {
        cin>>x;
        if(s.empty()) {
            s.push(x);
        }
        else {
            if(x - s.top() <= c);
            else {
                while(!s.empty())
                    s.pop();
            }
            s.push(x);

        }
    }
    cout<<s.size()<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,c = 0;
    char ch;
    list < int > m;
    list <int> :: iterator it,it1;
        while(scanf("%d",&a) != EOF) {

            if( a != 0 && a != -1) {
                m.push_back(a);
                c++;
                if( c == 1)
                    it = m.begin();
                else if ( c%2 != 0) {
                    it++;
                }
            }
            else if( a == -1) {
                if(c%2 == 0) {
                    printf("%d\n",*(it));
                    it1 = it;
                    it1++;
                    m.erase(it);
                    it = it1;
                }
                else {
                    printf("%d\n",*(it));
                    it1 = it;
                    it1--;
                    m.erase(it);
                    it = it1;
                }
                c--;
            }
            else {
                c = 0;
                m.clear();
                printf("\n");
            }

    }
}

#include<bits/stdc++.h>
using namespace std;
int main() {
      int x,y,x1,y1;
      scanf("%ld%ld%ld%ld",&x,&y,&x1,&y1);
      printf("%ld",max(abs(x1-x),abs(y1-y)));
      return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	char a[102];
	char b[102];
	scanf("%s",a);
	scanf("%s",b);
	for(int i = 0;a[i] != '\0';i++) {
		int x = a[i] - '0';
		int y = b[i] - '0';
		int z = x^y;
		cout<<z;
	}
}
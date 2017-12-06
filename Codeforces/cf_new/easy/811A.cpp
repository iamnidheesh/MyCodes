#include <iostream>
using namespace std;
int main() {
	long int a,b;
	cin>>a>>b;
	int chance = 1;
	int give = 1;
	int ans = 1;
	while(1) {
		if(chance == 1) {
			if(a-give >= 0) {
				chance = 2;
				a -= give;
				give++;
			}
			else {
				ans = 1;
				break;
			}
		}
		else {

			if(b-give >= 0) {
				chance = 1;
				b -= give;
				give++;
			}
			else {
				ans = 2;
				break;
			}
		}
	}
	if(ans == 1) {
		cout<<"Vladik";
	}
	else
		cout<<"Valera";
}
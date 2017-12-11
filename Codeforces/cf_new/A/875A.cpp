#include <iostream>
#include <vector>
using namespace std;
long int n;
long int digitSum(long int s) {
	int sum = 0;
	while(s > 0) {
		sum += s%10;
		s /= 10;
	}
	return sum;
}
int main() {
	cin>>n;
	long int m = n;
	int ct = 0;
	while(m > 0) {
		ct++;
		m /= 10;
	}
	long int start = n - 9*ct -1;
	vector <long int> v;
	for(int i = start;i < n;i++) {
		if(i + digitSum(i) == n) {
			v.push_back(i);
		}
	}
	cout<<v.size()<<endl;
	for(int i = 0;i < v.size();i++) {
		cout<<v[i]<<endl;
	}

}
#include <bits/stdc++.h>
using namespace std;
int n,k;
int freq[55],keySize[55];
int press[55];
int main() {
	cin>>n;
	int sum = 0;
	for(int i = 0;i < n;i++)
		cin>>freq[i];
	cin>>k;
	for(int i = 0;i < k;i++) {
		cin>>keySize[i];
		sum += keySize[i];
	}
	if(sum < n) {
		cout<<-1;
		return 0;
	}
	sort(freq,freq+n,greater <int> ());
	int num = 1;
	int index = 0;
	while(index < n) {
		for(int i = 0;i < k;i++) {
			if(keySize[i] > 0) {
				keySize[i]--;
				press[index] = num;
				index++;
				if(index == n)
					break;
			}
		}
		num++;
	}
	int ans = 0;
	for(int i = 0;i < n;i++) {
		ans += press[i]*freq[i];
	}
	cout<<ans;
}
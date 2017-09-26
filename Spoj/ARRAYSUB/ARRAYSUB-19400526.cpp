 #include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100010];
int main() {
	cin>>n;
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	cin>>k;
	deque <int> q(k);
	int i;
	for(i = 0;i < k;i++) {
		while(!(q.empty()) && a[i] >= a[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	for(i = k;i < n;i++) {
		cout<<a[q.front()]<<" ";
		while(!(q.empty()) && q.front() <= i-k)
			q.pop_front();
		while(!(q.empty()) && a[i] >= a[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	cout<<a[q.front()];
}
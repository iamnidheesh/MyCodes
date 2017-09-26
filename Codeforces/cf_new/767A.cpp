#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int main() {
	cin>>n;
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	priority_queue< int > pq;
	int cmp = n;
	for(int i = 0;i < n;i++) {
		if(a[i] == cmp) {
			if(pq.empty()) {
				printf("%d",a[i]);
				cmp--;
			}
			else {
				pq.push(a[i]);
				while(!pq.empty()) {
					if(pq.top() == cmp) {
						printf("%d ",pq.top());
						cmp--;
						pq.pop();
					}
					else
						break;
				}
			}

			printf("\n");
		}
		else  {
			printf("\n");
			pq.push(a[i]);
		}
	}

}
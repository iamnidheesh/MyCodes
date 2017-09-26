    #include <bits/stdc++.h>
    using namespace std;
    #define MAX 1005
    int A[MAX];
    int main() {
    	int n,t;
    	long int sum,ans;
    	scanf("%d",&t);
    	while(t--) {
    		sum=0;
    		scanf("%d",&n);
    		ans = 1e11;
    		for(int i=0;i<n;i++) {
    			scanf("%d",&A[i]);
    			sum=sum+(long int)A[i];
    			ans = min(ans,sum);
    		}
    		printf("%ld\n",(ans <= 0 ? ((-ans)+1 ): 0));
    		
    	}
    	return 0;
    } 
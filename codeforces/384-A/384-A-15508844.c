#include<stdio.h>
int main()
	{
	int n,i,k,j;scanf("%d",&n);
	if(n%2==0)
		printf("%d\n",(n*n)/2); 
	else
		printf("%d\n",(n-n/2)*(n-n/2)+(n/2)*(n/2));
	if(n==1)
		printf("C");
	else
	{for(i=1;i<=n/2;i++)
                {for(j=1;j<=n/2;j++)
                	printf("C.");
		if(n%2!=0)
			printf("C");
                printf("\n");
                for(k=1;k<=n/2;k++)
                    	printf(".C");
		if(n%2!=0)
			printf(".");		
                 printf("\n");}
		if(n%2!=0)
		{for(i=1;i<=n/2;i++)
			printf("C.");
		printf("C");}
	}

	return 0;
	}
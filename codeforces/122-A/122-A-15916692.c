#include<stdio.h>
int islucky(int m)
	{int flag=1;
	while(m)
                {if(m%10!=7&&m%10!=4)
                        {flag=0;break;}
                m=m/10;
                }
	return flag;
	}

int main()
	{
	int n,i,m,flag=0;
	scanf("%d",&n);
	m=n;
	if(islucky(m))
		printf("YES");
	else {
		for(i=4;i<n;i++)
			{
			if(n%i==0)
				if(islucky(i))
					{flag=1;break;}
				else
					continue;
					
			}
		if(flag)
			printf("YES");
		else
			printf("NO");
	}
	return 0;
	}
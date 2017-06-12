#include<stdio.h>
int gcd(int num1,int num2)
	{
	while(num1!=num2)
    {
        if(num1>num2)
            num1-=num2;
        else
            num2-=num1;
    }
    return num1;
	}
int main()
	{
	int a,b,n,t;
	scanf("%d%d%d",&a,&b,&n);
	while(1)
		{
		t=gcd(n,a);
		if(t<=n)
			n=n-t;
		else{printf("1");break;}
		if(n==0)
			{printf("0");break;}
		t=gcd(n,b);
		if(t<=n)
			n=n-t;
		else{printf("0");break;}
		if(n==0){printf("1");break;}
	}
	return 0;
	}
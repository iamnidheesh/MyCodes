#include<stdio.h>
int main()
	{
	int i,j,k,n,w=0,c=0;
	scanf("%d",&n);
	int a[5000];
	int l[5000];
	for(i=0;i<n;i++)
		{scanf("%d",&a[i]);l[i]=0;}
	for(i=0;i<n;i++)
		{if(a[i]==1)
			{for(j=0;j<n;j++)
				{if(a[j]==2)
					{for(k=0;k<n;k++)
						{if(a[k]==3)
							{w++;
							l[c]=i+1;l[c+1]=j+1;l[c+2]=k+1;c=c+3;
							a[i]=0;a[j]=0;a[k]=0;break;}
						}
					break;}
				}
		}
		}
	printf("%d\n",w);
	for(i=0;i<c;i=i+3)
		printf("%d %d %d\n",l[i],l[i+1],l[i+2]);
	return 0;
	}
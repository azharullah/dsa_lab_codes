#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

int validy(char b[])
{
		int p,q,flag=0;
		for(q=0;q<strlen(b);q++)
			{
				if( (b[q]>='a') && (b[q]<='z') )
					flag=0;
				else
					{
						flag=1;
						break;
					}
			if(flag==1)
				break;
			}
if(flag==0)
		return 1;
else 
		return 0;
}


void main()
{
	int i,j,n,x,z,k,t[100];
	char a[100][100],tc,b[100];
	clock_t start,end;
 	double exe_time;
	if(scanf("%d%c",&n,&tc)==2 && tc=='\n'&& n>0)
	{
	for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			strcpy(b,a[i]);
			if(validy(b))
				continue;
			else
			{
				printf("\n Enter a valid string \n");
				exit(1);
			}
		}
	
	start=clock();

	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i;j<n;j++)
		{
			if(strcmp(a[j],a[k])<0)
			{
				k=j;
			}
		}
			strcpy(t,a[i]);
			strcpy(a[i],a[k]);
			strcpy(a[k],t);
	}

	end=clock();

	printf(" \n The sorted array is \n");
	for(i=0;i<n;i++)
		printf("%s \n",a[i]);
	exe_time=(double)(end-start)/CLOCKS_PER_SEC;
 	printf("The execution time is %lf \n",exe_time);
	}
	else 
	{
		printf("\n Entered number is invalid \n");
	}
}

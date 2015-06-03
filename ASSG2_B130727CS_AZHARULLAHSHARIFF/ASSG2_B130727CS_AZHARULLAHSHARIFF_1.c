#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void main()
{
	int a[100],i,n,x;
	char tc;
	clock_t start,end;
 	double exe_time;
	if(scanf("%d%c",&n,&tc)==2 && tc=='\n'&& n>0)
	{
	for(i=0;i<n;i++)
		{
			if(!(scanf("%d%c",&a[i],&tc)==2 && tc=='\n'))
			{
				printf("\n Entered number is invalid \n");
				exit(1);
			}	
		}
	if(! (scanf("%d%c",&x,&tc)==2 && tc=='\n'))
	{
		printf("\n Entered number is invalid \n");
		exit(1);
	} 
	start=clock();
	search(a,x,0,n);
	end=clock();
	exe_time=(double)(end-start)/CLOCKS_PER_SEC;
 	printf("The execution time is %lf \n",exe_time);
	}
	else 
	{
		printf("\n Entered number is invalid \n");
		exit(1);
	}
}

int search(int a[],int x,int p,int n)
{
	if(p<n)
		{
			if(a[p]==x)
				{
					printf("\n %d \n",p);
					return 0;
				}
			else
				{
					p++;
					search(a,x,p,n);
				}
		}
	else
		{
			printf("\n -1 \n");
			return 0;
		}
}
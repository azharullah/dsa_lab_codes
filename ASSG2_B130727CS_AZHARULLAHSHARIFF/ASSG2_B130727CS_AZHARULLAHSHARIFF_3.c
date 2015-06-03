#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void main()
{
	int a[100],i,n,x,j,inv=0,tmp;
	clock_t start,end;
	char tc;
 	double exe_time;
	if(scanf("%d%c",&n,&tc)==2 && tc=='\n'&& n>0)
	{	
	for(i=0;i<n;i++)
		{
			if(!(scanf("%d%c",&a[i],&tc)==2 && tc=='\n'))
			{
				printf("\n Enter valid numbers \n");
				exit(1);
			}	
		}
	start=clock();
	/*for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
					{
						if( (i<j) && (a[i]>a[j]) )
							{
								inv++;
								//printf(" \n (i,j)=(%d,%d) , (a[i],a[j])=(%d,%d ) \n ",i,j,a[i],a[j]);
							}
					}
		}*/

	for(i=1;i<n;i++)
		{
			j=i;
			while( (j>0) && (a[j]<a[j-1]) )
				{
					tmp=a[j];
					a[j]=a[j-1];
					a[j-1]=tmp;
					j--;
					inv++;
				}
		}
	end=clock();
	printf("\n The elements in sorted order are: <");
	for(i=0;i<n;i++)	
		printf(" %d ,",a[i]);
	printf("> and there are %d inversions in the array \n",inv); 
	exe_time=(double)(end-start)/CLOCKS_PER_SEC;
 	printf("The execution time is %lf \n",exe_time);
	}
	else
	{
		printf("\n Enter valid element for n \n");
		exit(1);
	}
}

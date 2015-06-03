#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int pivot(float a[],int f,int l);

void quicksort(float a[],int f,int l)
{
	int p;
	if(f<l)
	{
		p=pivot(a,f,l);
		quicksort(a,f,p-1);
		quicksort(a,p+1,l);
	}	
}

int pivot(float a[],int f,int l)
{
	float temp;
	int x,y,n;
	n=a[l];
	x=f-1;
	for(y=f;y<l;y++)
	{
		if(a[y]<=n)
		{
			x++;
			temp=a[x];
			a[x]=a[y];
			a[y]=temp;
		}
	}
	temp=a[x+1];
	a[x+1]=a[l];
	a[l]=temp;
	return x+1;
}

int main()
 {
 	float a[100];
 	int i,j,n;
 	char tc;
 	clock_t start,end;
 	double exe_time;
 	if(scanf("%d%c",&n,&tc)==2 && tc=='\n'&& n>0)
 	{
 	for(i=0;i<n;i++)
 		{
 			if(!(scanf("%f%c",&a[i],&tc)==2 && tc=='\n'))
 			{
 				printf("\n Entered numbers are invalid \n");
 				exit(1);
 			}
 		}
 	start=clock();
 	if(n<0)
 	{
 		printf("\n n cannot be negative \n");
 		exit(1);
 	}
 	else if(n==0)
 	{
 		printf("\n n cannot be zero \n");
 		exit(1);	
 	}
 	quicksort(a,0,n-1);
 	end=clock();
 	printf("\n Sorted array is :\n");
 	for(i=0;i<n;i++)
 		printf("%f \n",a[i]);
 	exe_time=(double)(end-start)/CLOCKS_PER_SEC;
 	printf("The execution time is %lf \n",exe_time);
 	return 0;
 	}
 	else 
 	{
 		printf("\n Enter valid number \n");
 		exit(1);
 	}
 }
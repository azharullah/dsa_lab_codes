#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int minimum(int a[],int p,int q)
{
	int middle;
	if(p<q)
	{	
		middle = (p+q)/2;
	 	if(a[middle]>a[middle+1])
			return middle;
		else 
		{
			if(a[p]>a[middle])
				minimum(a,p,middle-1);
			else
				minimum(a,middle+1,q);
		}
	}
}

int initial_binser(int a[],int x,int p,int q,int min,int n)
{
	int pos;
	if(a[0]<=x)
		pos=binser(a,1,min,x);
	else
		pos=binser(a,min+1,n,x);
	return pos;
}

int binser(int a[],int p,int q,int x)
{
	int mid;

	if(p > q)
		return -1;
	mid = (p+q)/2;
	if(x==a[mid])
		return mid;
	else 
	{
		if(x <= a[mid])
			binser(a,p,mid-1,x);
		else
			binser(a,mid+1,q,x);
	}
}

void main()
{
	int a[100],i,n,x,z,t,min;
	char tc;
	clock_t start,end;
 	double exe_time;
	if(scanf("%d%c",&n,&tc)==2 && tc=='\n'&& n>0)
	{
	for(i=0;i<n;i++)
		{
			if(!(scanf("%d%c",&a[i],&tc)==2 && tc=='\n'))
			{
				printf("\n Entered number is invalid\n");
				exit(1);
			}		
		}
	scanf("%d",&x);  //to take x (ele to be searched) 

	if(n==1 && a[0]==x)
	{
		printf("\n Element is found at position 0 \n");
		exit(1);
	}
	else if(n==1 && a[0]!=x)
	{
		printf("\nElement is not found \n");
		exit(1);
	}
	
	min=minimum(a,0,n);
	//printf("\n%d\n",min);
	z=initial_binser(a,x,0,n,min,n);
	if(z==-1)
		printf("\n Element is not found \n");
	else 	
		printf("\nThe element is found at position %d \n",z); 
	}
	else 
	{
		printf("\n Entered number is invalid \n");
		exit(1);
	}
}



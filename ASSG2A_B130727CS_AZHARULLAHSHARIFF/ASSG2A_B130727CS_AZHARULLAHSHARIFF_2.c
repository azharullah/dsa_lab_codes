#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int ismallest(int a[],int f,int l,int i);
int pivot(int a[],int f,int l);
int randompartition(int a[],int f,int l);

void main()
{
	int a[100],i,n,x,y;
	float med;
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
	start=clock();
	if(n%2!=0)
		med=ismallest(a,0,n-1,(n/2+1));
	else
		{
			x=ismallest(a,0,n-1,(n/2+1));
			//printf("x=%d",x);
			y=ismallest(a,0,n-1,n/2);
			//printf("y=%d",y);
			med=(float)(x+y)/2;
		}
	end=clock();
	printf("\nMedian of the numbers is %f \n",med);
	exe_time=(double)(end-start)/CLOCKS_PER_SEC;
 	printf("The execution time is %lf \n",exe_time);
	}
	else 
	{
		printf("\n Entered number is invalid \n");
		exit(1);
	}
}

int ismallest(int a[],int f,int l,int i)
{
	int p,q;
	if(f==l)
		{
			//printf("\n **&&%d ie %d is returned &&** \n",l,a[l]);
			return a[l];
			
		}
	//printf("\n %d-->%d smallest number is %d\n",f,l,a[l]);
	p=randompartition(a,f,l);
	q=p-f+1;
	if(i==q)
		{
			//printf("\n **%d ie %d is returned ** \n",p,a[p]);
			return a[p];
			
		}
	else if(i<q)
		return ismallest(a,f,p-1,i);
	else 
		return ismallest(a,p+1,l,i);
}

int randompartition(int a[],int f,int l)
{
	int i,temp;
	i=rand() % (l-f+1) + f;
	temp=a[l];
	a[l]=a[i];
	a[i]=temp;
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
